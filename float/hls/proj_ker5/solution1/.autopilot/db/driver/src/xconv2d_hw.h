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
// 0x28 : Data signal of kernel_in_0_3
//        bit 31~0 - kernel_in_0_3[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of kernel_in_0_4
//        bit 31~0 - kernel_in_0_4[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of kernel_in_1_0
//        bit 31~0 - kernel_in_1_0[31:0] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of kernel_in_1_1
//        bit 31~0 - kernel_in_1_1[31:0] (Read/Write)
// 0x44 : reserved
// 0x48 : Data signal of kernel_in_1_2
//        bit 31~0 - kernel_in_1_2[31:0] (Read/Write)
// 0x4c : reserved
// 0x50 : Data signal of kernel_in_1_3
//        bit 31~0 - kernel_in_1_3[31:0] (Read/Write)
// 0x54 : reserved
// 0x58 : Data signal of kernel_in_1_4
//        bit 31~0 - kernel_in_1_4[31:0] (Read/Write)
// 0x5c : reserved
// 0x60 : Data signal of kernel_in_2_0
//        bit 31~0 - kernel_in_2_0[31:0] (Read/Write)
// 0x64 : reserved
// 0x68 : Data signal of kernel_in_2_1
//        bit 31~0 - kernel_in_2_1[31:0] (Read/Write)
// 0x6c : reserved
// 0x70 : Data signal of kernel_in_2_2
//        bit 31~0 - kernel_in_2_2[31:0] (Read/Write)
// 0x74 : reserved
// 0x78 : Data signal of kernel_in_2_3
//        bit 31~0 - kernel_in_2_3[31:0] (Read/Write)
// 0x7c : reserved
// 0x80 : Data signal of kernel_in_2_4
//        bit 31~0 - kernel_in_2_4[31:0] (Read/Write)
// 0x84 : reserved
// 0x88 : Data signal of kernel_in_3_0
//        bit 31~0 - kernel_in_3_0[31:0] (Read/Write)
// 0x8c : reserved
// 0x90 : Data signal of kernel_in_3_1
//        bit 31~0 - kernel_in_3_1[31:0] (Read/Write)
// 0x94 : reserved
// 0x98 : Data signal of kernel_in_3_2
//        bit 31~0 - kernel_in_3_2[31:0] (Read/Write)
// 0x9c : reserved
// 0xa0 : Data signal of kernel_in_3_3
//        bit 31~0 - kernel_in_3_3[31:0] (Read/Write)
// 0xa4 : reserved
// 0xa8 : Data signal of kernel_in_3_4
//        bit 31~0 - kernel_in_3_4[31:0] (Read/Write)
// 0xac : reserved
// 0xb0 : Data signal of kernel_in_4_0
//        bit 31~0 - kernel_in_4_0[31:0] (Read/Write)
// 0xb4 : reserved
// 0xb8 : Data signal of kernel_in_4_1
//        bit 31~0 - kernel_in_4_1[31:0] (Read/Write)
// 0xbc : reserved
// 0xc0 : Data signal of kernel_in_4_2
//        bit 31~0 - kernel_in_4_2[31:0] (Read/Write)
// 0xc4 : reserved
// 0xc8 : Data signal of kernel_in_4_3
//        bit 31~0 - kernel_in_4_3[31:0] (Read/Write)
// 0xcc : reserved
// 0xd0 : Data signal of kernel_in_4_4
//        bit 31~0 - kernel_in_4_4[31:0] (Read/Write)
// 0xd4 : reserved
// 0xd8 : Data signal of img_size
//        bit 31~0 - img_size[31:0] (Read/Write)
// 0xdc : reserved
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
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_3_DATA 0x28
#define XCONV2D_CONTROL_BITS_KERNEL_IN_0_3_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_4_DATA 0x30
#define XCONV2D_CONTROL_BITS_KERNEL_IN_0_4_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_0_DATA 0x38
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_1_DATA 0x40
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_2_DATA 0x48
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_3_DATA 0x50
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_3_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_4_DATA 0x58
#define XCONV2D_CONTROL_BITS_KERNEL_IN_1_4_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_0_DATA 0x60
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_1_DATA 0x68
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_2_DATA 0x70
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_3_DATA 0x78
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_3_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_4_DATA 0x80
#define XCONV2D_CONTROL_BITS_KERNEL_IN_2_4_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_3_0_DATA 0x88
#define XCONV2D_CONTROL_BITS_KERNEL_IN_3_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_3_1_DATA 0x90
#define XCONV2D_CONTROL_BITS_KERNEL_IN_3_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_3_2_DATA 0x98
#define XCONV2D_CONTROL_BITS_KERNEL_IN_3_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_3_3_DATA 0xa0
#define XCONV2D_CONTROL_BITS_KERNEL_IN_3_3_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_3_4_DATA 0xa8
#define XCONV2D_CONTROL_BITS_KERNEL_IN_3_4_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_4_0_DATA 0xb0
#define XCONV2D_CONTROL_BITS_KERNEL_IN_4_0_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_4_1_DATA 0xb8
#define XCONV2D_CONTROL_BITS_KERNEL_IN_4_1_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_4_2_DATA 0xc0
#define XCONV2D_CONTROL_BITS_KERNEL_IN_4_2_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_4_3_DATA 0xc8
#define XCONV2D_CONTROL_BITS_KERNEL_IN_4_3_DATA 32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_4_4_DATA 0xd0
#define XCONV2D_CONTROL_BITS_KERNEL_IN_4_4_DATA 32
#define XCONV2D_CONTROL_ADDR_IMG_SIZE_DATA      0xd8
#define XCONV2D_CONTROL_BITS_IMG_SIZE_DATA      32

