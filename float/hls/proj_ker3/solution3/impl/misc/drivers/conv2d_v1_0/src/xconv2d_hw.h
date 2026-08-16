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
// 0x40 : Data signal of img_size
//        bit 31~0 - img_size[31:0] (Read/Write)
// 0x44 : reserved
// 0x10 ~
// 0x1f : Memory 'kernel_in_0' (3 * 32b)
//        Word n : bit [31:0] - kernel_in_0[n]
// 0x20 ~
// 0x2f : Memory 'kernel_in_1' (3 * 32b)
//        Word n : bit [31:0] - kernel_in_1[n]
// 0x30 ~
// 0x3f : Memory 'kernel_in_2' (3 * 32b)
//        Word n : bit [31:0] - kernel_in_2[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XCONV2D_CONTROL_ADDR_AP_CTRL          0x00
#define XCONV2D_CONTROL_ADDR_GIE              0x04
#define XCONV2D_CONTROL_ADDR_IER              0x08
#define XCONV2D_CONTROL_ADDR_ISR              0x0c
#define XCONV2D_CONTROL_ADDR_IMG_SIZE_DATA    0x40
#define XCONV2D_CONTROL_BITS_IMG_SIZE_DATA    32
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE 0x10
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH 0x1f
#define XCONV2D_CONTROL_WIDTH_KERNEL_IN_0     32
#define XCONV2D_CONTROL_DEPTH_KERNEL_IN_0     3
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE 0x20
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH 0x2f
#define XCONV2D_CONTROL_WIDTH_KERNEL_IN_1     32
#define XCONV2D_CONTROL_DEPTH_KERNEL_IN_1     3
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE 0x30
#define XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH 0x3f
#define XCONV2D_CONTROL_WIDTH_KERNEL_IN_2     32
#define XCONV2D_CONTROL_DEPTH_KERNEL_IN_2     3

