// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - enable ap_done interrupt (Read/Write)
//        bit 1  - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - ap_done (COR/TOW)
//        bit 1  - ap_ready (COR/TOW)
//        others - reserved
// 0x10 : Data signal of kernel_in_0_0
//        bit 31~0 - kernel_in_0_0[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of kernel_in_0_1
//        bit 31~0 - kernel_in_0_1[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of kernel_in_0_2
//        bit 31~0 - kernel_in_0_2[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of kernel_in_1_0
//        bit 31~0 - kernel_in_1_0[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of kernel_in_1_1
//        bit 31~0 - kernel_in_1_1[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of kernel_in_1_2
//        bit 31~0 - kernel_in_1_2[31:0] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of kernel_in_2_0
//        bit 31~0 - kernel_in_2_0[31:0] (Read/Write)
// 0x44 : reserved
// 0x48 : Data signal of kernel_in_2_1
//        bit 31~0 - kernel_in_2_1[31:0] (Read/Write)
// 0x4c : reserved
// 0x50 : Data signal of kernel_in_2_2
//        bit 31~0 - kernel_in_2_2[31:0] (Read/Write)
// 0x54 : reserved
// 0x58 : Data signal of img_size
//        bit 31~0 - img_size[31:0] (Read/Write)
// 0x5c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XCONV2D_CONTROL_ADDR_AP_CTRL            0x00
#define XCONV2D_CONTROL_ADDR_GIE                0x04
#define XCONV2D_CONTROL_ADDR_IER                0x08
#define XCONV2D_CONTROL_ADDR_ISR                0x0c
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_0_DATA 0x10
#define XCONV2D_CONTROL_BITS_KERNEL_IN_0_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_1_DATA 0x18
#define XCONV2D_CONTROL_BITS_KERNEL_IN_0_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_2_DATA 0x20
#define XCONV2D_CONTROL_BITS_KERNEL_IN_0_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_0_DATA 0x28
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_1_DATA 0x30
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_2_DATA 0x38
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_0_DATA 0x40
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_1_DATA 0x48
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_2_DATA 0x50
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_2_DATA 32
#define XCONV2D_CONTROL_ADDR_IMG_SIZE_DATA      0x58
#define XCONV2D_CONTROL_BITS_IMG_SIZE_DATA      32

