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

void XConv2d_Set_kernel_in_0_0(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_0_DATA, Data);
}

u32 XConv2d_Get_kernel_in_0_0(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_0_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_0_1(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_1_DATA, Data);
}

u32 XConv2d_Get_kernel_in_0_1(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_1_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_0_2(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_2_DATA, Data);
}

u32 XConv2d_Get_kernel_in_0_2(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_2_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_0_3(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_3_DATA, Data);
}

u32 XConv2d_Get_kernel_in_0_3(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_3_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_0_4(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_4_DATA, Data);
}

u32 XConv2d_Get_kernel_in_0_4(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_0_4_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_1_0(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_0_DATA, Data);
}

u32 XConv2d_Get_kernel_in_1_0(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_0_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_1_1(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_1_DATA, Data);
}

u32 XConv2d_Get_kernel_in_1_1(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_1_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_1_2(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_2_DATA, Data);
}

u32 XConv2d_Get_kernel_in_1_2(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_2_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_1_3(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_3_DATA, Data);
}

u32 XConv2d_Get_kernel_in_1_3(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_3_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_1_4(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_4_DATA, Data);
}

u32 XConv2d_Get_kernel_in_1_4(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_1_4_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_2_0(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_0_DATA, Data);
}

u32 XConv2d_Get_kernel_in_2_0(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_0_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_2_1(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_1_DATA, Data);
}

u32 XConv2d_Get_kernel_in_2_1(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_1_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_2_2(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_2_DATA, Data);
}

u32 XConv2d_Get_kernel_in_2_2(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_2_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_2_3(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_3_DATA, Data);
}

u32 XConv2d_Get_kernel_in_2_3(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_3_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_2_4(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_4_DATA, Data);
}

u32 XConv2d_Get_kernel_in_2_4(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_2_4_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_3_0(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_0_DATA, Data);
}

u32 XConv2d_Get_kernel_in_3_0(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_0_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_3_1(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_1_DATA, Data);
}

u32 XConv2d_Get_kernel_in_3_1(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_1_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_3_2(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_2_DATA, Data);
}

u32 XConv2d_Get_kernel_in_3_2(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_2_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_3_3(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_3_DATA, Data);
}

u32 XConv2d_Get_kernel_in_3_3(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_3_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_3_4(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_4_DATA, Data);
}

u32 XConv2d_Get_kernel_in_3_4(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_3_4_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_4_0(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_0_DATA, Data);
}

u32 XConv2d_Get_kernel_in_4_0(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_0_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_4_1(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_1_DATA, Data);
}

u32 XConv2d_Get_kernel_in_4_1(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_1_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_4_2(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_2_DATA, Data);
}

u32 XConv2d_Get_kernel_in_4_2(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_2_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_4_3(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_3_DATA, Data);
}

u32 XConv2d_Get_kernel_in_4_3(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_3_DATA);
    return Data;
}

void XConv2d_Set_kernel_in_4_4(XConv2d *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_4_DATA, Data);
}

u32 XConv2d_Get_kernel_in_4_4(XConv2d *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_CONTROL_ADDR_KERNEL_IN_4_4_DATA);
    return Data;
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

