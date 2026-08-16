#include "twodconv.h"

union float_bits {
    float    f;
    unsigned u;
};

static inline data_t unpack(ap_int<32> raw) {
#ifdef USE_FIXED
    data_t val;
    val.range() = raw.range(DATA_WIDTH - 1, 0);
    return val;
#else
    float_bits fb;
    fb.u = (unsigned)raw;
    return fb.f;
#endif
}

static inline ap_int<32> pack(data_t val) {
#ifdef USE_FIXED
    ap_int<32> raw = 0;
    raw.range(DATA_WIDTH - 1, 0) = val.range();
    return raw;
#else
    float_bits fb;
    fb.f = val;
    return (ap_int<32>)fb.u;
#endif
}

void conv2d(hls::stream<axis_pkt_t> &in_stream,
            hls::stream<axis_pkt_t> &out_stream,
			data_t kernel_in[kernel_size][kernel_size],
            int img_size)
{
#pragma HLS INTERFACE axis port=in_stream
#pragma HLS INTERFACE axis port=out_stream
#pragma HLS INTERFACE s_axilite port=img_size
#pragma HLS INTERFACE s_axilite port=kernel_in
#pragma HLS INTERFACE s_axilite port=return

    const int pad = (kernel_size - 1) / 2;

    static data_t line_buf[kernel_size - 1][MAX_IMG_WIDTH];
    static data_t window[kernel_size][kernel_size];

#pragma HLS ARRAY_PARTITION dim=1 type=complete variable=line_buf
#pragma HLS BIND_STORAGE variable=line_buf type=ram_2p impl=bram
#pragma HLS ARRAY_PARTITION dim=0 type=complete variable=window

    axis_pkt_t in_pkt, out_pkt;
    data_t acc = 0;

    int virt_size = img_size + 2 * pad;
    ROW_SLIDE:
    for (int row = 0; row < virt_size; row++) {
    	COL_SLIDE:
        for (int col = 0; col < virt_size; col++)
{

        	UPDATE_WINDOW_ROW:
            for (int i = 0; i < kernel_size; i++) {
            	UPDATE_WINDOW_COL:
                for (int j = 0; j < kernel_size - 1; j++) {
                    window[i][j] = window[i][j + 1];
                }
            }

            data_t new_pixel = 0.0f;

            if (row >= pad && row < img_size + pad &&
                col >= pad && col < img_size + pad) {
                in_pkt = in_stream.read();
                new_pixel = unpack(in_pkt.data);
            }
            UPDATE_BUF:
            for (int i = 0; i < kernel_size - 1; i++) {
                data_t val = line_buf[i][col];
                window[i][kernel_size - 1] = val;

                if (i < kernel_size - 2) {
                    line_buf[i][col] = line_buf[i + 1][col];
                } else {
                    line_buf[i][col] = new_pixel;
                }
            }
            window[kernel_size - 1][kernel_size - 1] = new_pixel;

            // out pixel compute
            if (row >= kernel_size - 1 && col >= kernel_size - 1) {
                acc = 0;
                MACi:
                for (int i = 0; i < kernel_size; i++) {
                	MACj:
                    for (int j = 0; j < kernel_size; j++) {
                        int kernel_row = kernel_size - 1 - i;
                        int kernel_col = kernel_size - 1 - j;
                        acc += window[i][j] * kernel_in[kernel_row][kernel_col];
                    }
                }

                out_pkt.data = pack(acc);
                out_pkt.keep = -1;
                out_pkt.strb = -1;
                out_pkt.user = 0;
                out_pkt.id   = 0;
                out_pkt.dest = 0;
                out_pkt.last = ((row == virt_size - 1) && (col == virt_size - 1)) ? 1 : 0;
                out_stream.write(out_pkt);
            }
        }
    }
}
