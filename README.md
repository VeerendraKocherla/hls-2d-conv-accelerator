# Floating-Point 2D Convolution — Sliding Window + Line Buffer Architecture

This folder contains the **32-bit IEEE-754 floating-point** implementation of the HLS 2D convolution accelerator, built around a **sliding-window + line-buffer** streaming architecture. This is my (K V Veerendra Babu's) individual contribution to the project: the floating-point HLS kernel, its Pareto design-space exploration, IP/bitstream generation, and PYNQ deployment. (The separable-convolution work under a different scope of the project is not covered here.)

## Architecture overview

The core `conv2d` kernel (`hls/twodconv.cpp`) streams pixels in over `hls::axis` and reconstructs a `kernel_size × kernel_size` sliding window on the fly using `kernel_size - 1` line buffers, rather than buffering the whole image:

- **Line buffers**: `data_t line_buf[kernel_size - 1][MAX_IMG_WIDTH]`, holding the previous `kernel_size - 1` rows of the (zero-padded) image.
- **Window register**: `data_t window[kernel_size][kernel_size]`, shifted left by one column every cycle and refilled from the line buffer + incoming pixel in the rightmost column.
- **Zero padding** is applied implicitly by iterating over a "virtual" image of size `img_size + 2*pad` and only reading/writing on valid streaming boundaries, avoiding any explicit border-handling logic in the datapath.
- **MAC**: once the window is full (`row >= kernel_size-1 && col >= kernel_size-1`), the kernel is convolved (not correlated — indices are flipped: `kernel_row = kernel_size-1-i`) against the window and the result is packed back into an AXI-Stream word.

Since HLS `hls::stream` cannot carry a native `float` payload over `ap_axis`, pixels and kernel weights are transported as raw 32-bit patterns and reinterpreted using a `union float_bits { float f; unsigned u; }`, via the `pack()` / `unpack()` helper functions. This keeps the datapath entirely in `float` while still using the standard AXI4-Stream (`ap_axis<32,1,1,1>`) interface.

### Key HLS pragmas

```cpp
#pragma HLS ARRAY_PARTITION dim=1 type=complete variable=line_buf
#pragma HLS BIND_STORAGE     variable=line_buf type=ram_2p impl=bram
#pragma HLS ARRAY_PARTITION dim=0 type=complete variable=window
```

- `line_buf` is fully partitioned along `dim=1` (one BRAM per row) and explicitly bound to `ram_2p` (true dual-port) BRAM, so each row can be read and written in the same cycle.
- `window` is fully partitioned into registers so every tap is available combinationally to the MAC tree in the same cycle — this is what makes `II = 1` achievable at all.
- `img_size` and the `kernel_in` coefficients are exposed over **AXI-Lite**; pixels flow over **AXI-Stream** in and out.

For `MAX_IMG_WIDTH = 256`, each line buffer row is `256 × 32 = 8192` bits (well under one 18K BRAM), and with `dim=1` fully partitioned the design uses exactly `kernel_size - 1` BRAM_18K blocks — 2 for a 3×3 kernel, 4 for a 5×5 kernel.

## Pareto exploration (solutions)

Four HLS solutions were synthesized per kernel size to trade off throughput against DSP usage, all under `hls/proj_ker3` and `hls/proj_ker5`:

| Solution | Directive | Target clock | Effect |
|---|---|---|---|
| **solution1** (deployed) | `set_directive_pipeline -II 1 "conv2d/COL_SLIDE"` | 250 ns / 10 ns* | Fully pipelined, **II = 1** |
| solution2 | `set_directive_allocation -type operation -limit 1 "conv2d/COL_SLIDE" fmul` / `fadd` | 10 ns | Shares 1 floating-point multiplier/adder across the MAC tree — cuts DSPs, raises II |
| solution3 | `set_directive_pipeline -off "conv2d"` | 10 ns | Pipelining disabled entirely — minimum resources, worst throughput |
| solution4 | `set_directive_pipeline -II 1 "conv2d/COL_SLIDE"` | 40 ns | Same as solution1 at a relaxed clock target, for comparison |

*solution1 for the 3×3 kernel was synthesized at a 250 ns target in this run; solution1 for the 5×5 kernel uses the standard 10 ns target. Both hit II = 1 on `COL_SLIDE`.

**solution1 is the version exported to IP and deployed on PYNQ** for both kernel sizes (see `kernel3float.tcl` / `kernel5float.tcl`, which point at `hls/proj_ker3/solution1/impl/ip` and `hls/proj_ker5/solution1/impl/ip`).

### Synthesis results — kernel = 3×3 (`hls/proj_ker3`)

| Solution | Clock (target/est.) | II | Latency (min–max cycles) | BRAM_18K | DSP | FF | LUT |
|---|---|---|---|---|---|---|---|
| solution1 | 0.25 µs / 0.240 µs | **1** | 4363 – 16907 | 2 | 48 | 1821 | 7833 |
| solution2 | 10 ns / 8.51 ns | 9 | 39247 – 152143 | 2 | 8 | 2954 | 2506 |
| solution3 | 10 ns / 7.26 ns | — (not pipelined) | 95965 – 2163461 | 2 | 5 | 1757 | 1982 |
| solution4 | 40 ns / 34.96 ns | **1** | 4377 – 16921 | 2 | 48 | 5220 | 8057 |

### Synthesis results — kernel = 5×5 (`hls/proj_ker5`, solution1)

II = 1 achieved on `COL_SLIDE` at a 10 ns target (8.51 ns estimated). Resource usage: **4 BRAM_18K, 148 DSP, 18366 FF, 25376 LUT** (67% DSP utilization on the xc7z020).

### Resource trade-off summary (from project report)

| Config | BRAM | DSP | FF | LUT |
|---|---|---|---|---|
| Kernel = 3, float | 2 | 48 | 6094–7833† | 8057–8108† |
| Kernel = 5, float | 4 | 148 | 18010–18366† | 25060–25376† |

†Minor variation between report figures and this synthesis run's `solution1` report; both correspond to the II=1 configuration.

Going from a 3×3 to a 5×5 kernel scales DSPs from 48 → 148 (~3×) for the fully-pipelined floating-point design, since each additional tap needs its own floating-point multiplier and the adder tree grows accordingly — floating-point MACs are considerably more DSP-hungry than their fixed-point counterparts at the same II.

## Files

```
float/
├── hls/
│   ├── twodconv.cpp          # conv2d kernel: sliding window + line buffer, float datapath
│   ├── twodconv.h             # interface, kernel_size / MAX_IMG_WIDTH config
│   ├── common.h                # data_t = float
│   ├── twodconv_tb.cpp        # C testbench: reads input/kernel/expected .txt, checks tolerance
│   ├── generate_test.py       # NumPy/SciPy reference generator (input.txt, kernel.txt, expected_output.txt)
│   ├── input.txt / kernel.txt / expected_output.txt   # generated test vectors
│   └── proj_ker3/ , proj_ker5/  # Vitis HLS projects (solutions 1-4) with csynth reports and exported IP
├── kernel3float.tcl           # Vivado block-design script for the 3x3 float IP (uses proj_ker3/solution1)
├── kernel5float.tcl           # Vivado block-design script for the 5x5 float IP (uses proj_ker5/solution1)
└── pynq/
    ├── conv2d_designfloat_wrapper.bit/.hwh   # bitstream + hardware handoff, 3x3 kernel
    ├── design_k5_wrapper.bit/.hwh             # bitstream + hardware handoff, 5x5 kernel
    ├── float_64_3.ipynb, float_128_3.ipynb    # PYNQ deployment/test, 3x3 kernel, 64x64 & 128x128 images
    └── float_64_5.ipynb, float_128_5.ipynb    # PYNQ deployment/test, 5x5 kernel, 64x64 & 128x128 images
```

## Testbench / verification

`generate_test.py` produces a random grayscale image (`randint(0,255)/255`) and a random kernel (`uniform(-1, 1)`), and computes the ground truth via `scipy.ndimage.convolve` (zero padding, `mode='constant'`). `twodconv_tb.cpp` packs the image into AXI-Stream words, invokes `conv2d`, unpacks the output stream, and compares against `expected_output.txt` with a tolerance of `1e-4`.

## Running C-simulation / synthesis (Vitis HLS 2021.1)

```tcl
open_project proj_ker3      ;# or proj_ker5
set_top conv2d
add_files twodconv.cpp
add_files -tb twodconv_tb.cpp
open_solution "solution1"
set_part xc7z020-clg400-1
create_clock -period 10 -name default
set_directive_pipeline -II 1 "conv2d/COL_SLIDE"
csim_design
csynth_design
export_design -format ip_catalog
```

## PYNQ deployment

The IP exposes kernel coefficients and `img_size` over AXI-Lite, and pixels over AXI-Stream via an AXI DMA. From the notebooks in `pynq/`:

```python
from pynq import Overlay, allocate
ol = Overlay("conv2d_designfloat_wrapper.bit")   # or design_k5_wrapper.bit
dma, conv_stream, hw_timer = ol.axi_dma_0, ol.conv2d_0, ol.axi_timer_0

# kernel coefficients, one 32-bit float per AXI-Lite register (0x10, 0x18, 0x20, ... for 3x3;
# 0x10 through 0xd0 for 5x5), each packed via struct.pack('<f', value)
conv_stream.write(0x10, float_to_raw_int(kernel[0][0]))
...
conv_stream.write(0x58, inp_size)   # image size (0xd8 for the 5x5 IP)
conv_stream.write(0x00, 0x01)       # ap_start

dma.sendchannel.transfer(in_buf)    # in_buf/out_buf: np.float32 arrays
dma.recvchannel.transfer(out_buf)
dma.sendchannel.wait()
dma.recvchannel.wait()
```

### Measured performance on PYNQ-Z2

| Config | Axi timer DMA (µs/sample) | SciPy (µs/sample) | Max abs. error |
|---|---|---|---|
| img 64, k 3 | 1.325 | 0.689 | 1.97e-7 |
| img 128, k 3 | 0.113 | 0.545 | 5.36e-7 |
| img 64, k 5 | 0.514 | 0.986 | 1.05e-6 |
| img 128, k 5 | 0.08 | 1.43 | 7.59e-7 |

Max burst size for the 3×3 float configuration is 16; all other configurations use a max burst size of 256. BRAM usage stays at `kernel_size - 1` for image sizes up to 512 (max image size in this project was capped at 256).

Floating-point residual error against the SciPy reference is on the order of `1e-6`–`1e-7` — essentially IEEE-754 rounding noise, since (unlike the fixed-point version) there is no quantization of the input, kernel, or accumulator.

## My contribution (per project report)

- Test vector generation in Python (`generate_test.py`)
- HLS kernel for the floating-point sliding-window + line-buffer convolution (`twodconv.cpp/.h`)
- Pareto design points for the floating-point design (solutions 1–4)
- IP and bitstream generation for the floating-point design
- PYNQ deployment and benchmarking for the floating-point design
