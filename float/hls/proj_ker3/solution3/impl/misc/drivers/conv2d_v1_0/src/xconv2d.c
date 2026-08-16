// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.1 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xconv2d.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XConv2d_CfgInitialize(XConv2d *InstancePtr, XConv2d_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XConv2d_Start(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL) & 0x80;
    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XConv2d_IsDone(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XConv2d_IsIdle(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XConv2d_IsReady(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XConv2d_EnableAutoRestart(XConv2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XConv2d_DisableAutoRestart(XConv2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_AP_CTRL, 0);
}

void XConv2d_Set_img_size(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IMG_SIZE_DATA, Data);
}

u32 XConv2d_Get_img_size(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IMG_SIZE_DATA);
    return Data;
}

u32 XConv2d_Get_kernel_in_0_BaseAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE);
}

u32 XConv2d_Get_kernel_in_0_HighAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH);
}

u32 XConv2d_Get_kernel_in_0_TotalBytes(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + 1);
}

u32 XConv2d_Get_kernel_in_0_BitWidth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_WIDTH_KERNEL_IN_0;
}

u32 XConv2d_Get_kernel_in_0_Depth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_DEPTH_KERNEL_IN_0;
}

u32 XConv2d_Write_kernel_in_0_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_0_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConv2d_Write_kernel_in_0_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_0_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_0_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_0_BASE + offset + i);
    }
    return length;
}

u32 XConv2d_Get_kernel_in_1_BaseAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE);
}

u32 XConv2d_Get_kernel_in_1_HighAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH);
}

u32 XConv2d_Get_kernel_in_1_TotalBytes(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + 1);
}

u32 XConv2d_Get_kernel_in_1_BitWidth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_WIDTH_KERNEL_IN_1;
}

u32 XConv2d_Get_kernel_in_1_Depth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_DEPTH_KERNEL_IN_1;
}

u32 XConv2d_Write_kernel_in_1_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_1_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConv2d_Write_kernel_in_1_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_1_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_1_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_1_BASE + offset + i);
    }
    return length;
}

u32 XConv2d_Get_kernel_in_2_BaseAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE);
}

u32 XConv2d_Get_kernel_in_2_HighAddress(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH);
}

u32 XConv2d_Get_kernel_in_2_TotalBytes(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + 1);
}

u32 XConv2d_Get_kernel_in_2_BitWidth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_WIDTH_KERNEL_IN_2;
}

u32 XConv2d_Get_kernel_in_2_Depth(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCONV2D_CONTROL_DEPTH_KERNEL_IN_2;
}

u32 XConv2d_Write_kernel_in_2_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_2_Words(XConv2d *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XConv2d_Write_kernel_in_2_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XConv2d_Read_kernel_in_2_Bytes(XConv2d *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCONV2D_CONTROL_ADDR_KERNEL_IN_2_HIGH - XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XCONV2D_CONTROL_ADDR_KERNEL_IN_2_BASE + offset + i);
    }
    return length;
}

void XConv2d_InterruptGlobalEnable(XConv2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_GIE, 1);
}

void XConv2d_InterruptGlobalDisable(XConv2d *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_GIE, 0);
}

void XConv2d_InterruptEnable(XConv2d *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IER);
    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IER, Register | Mask);
}

void XConv2d_InterruptDisable(XConv2d *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IER);
    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IER, Register & (~Mask));
}

void XConv2d_InterruptClear(XConv2d *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_ISR, Mask);
}

u32 XConv2d_InterruptGetEnabled(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_IER);
}

u32 XConv2d_InterruptGetStatus(XConv2d *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_ISR);
}

