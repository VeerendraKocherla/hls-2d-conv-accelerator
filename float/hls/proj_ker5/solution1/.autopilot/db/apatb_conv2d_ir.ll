; ModuleID = 'D:/IITMadrasICS/1-2/EE5332Project/float/proj_float5/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"class.hls::stream" = type { %"struct.hls::axis" }
%"struct.hls::axis" = type { %struct.ap_int, %struct.ap_uint, %struct.ap_uint, %struct.ap_uint.2, %struct.ap_uint.2, %struct.ap_uint.2, %struct.ap_uint.2 }
%struct.ap_int = type { %struct.ap_int_base }
%struct.ap_int_base = type { %struct.ssdm_int }
%struct.ssdm_int = type { i32 }
%struct.ap_uint = type { %struct.ap_int_base.0 }
%struct.ap_int_base.0 = type { %struct.ssdm_int.1 }
%struct.ssdm_int.1 = type { i4 }
%struct.ap_uint.2 = type { %struct.ap_int_base.3 }
%struct.ap_int_base.3 = type { %struct.ssdm_int.4 }
%struct.ssdm_int.4 = type { i1 }

; Function Attrs: noinline
define void @apatb_conv2d_ir(%"class.hls::stream"* %in_stream, %"class.hls::stream"* %out_stream, [5 x float]* %kernel_in, i32 %img_size) local_unnamed_addr #0 {
entry:
  %in_stream_copy.data = alloca i32
  %in_stream_copy.keep = alloca i4
  %in_stream_copy.strb = alloca i4
  %in_stream_copy.user = alloca i1
  %in_stream_copy.last = alloca i1
  %in_stream_copy.id = alloca i1
  %in_stream_copy.dest = alloca i1
  %out_stream_copy.data = alloca i32
  %out_stream_copy.keep = alloca i4
  %out_stream_copy.strb = alloca i4
  %out_stream_copy.user = alloca i1
  %out_stream_copy.last = alloca i1
  %out_stream_copy.id = alloca i1
  %out_stream_copy.dest = alloca i1
  %kernel_in_copy_0_0 = alloca float, align 512
  %kernel_in_copy_0_1 = alloca float, align 512
  %kernel_in_copy_0_2 = alloca float, align 512
  %kernel_in_copy_0_3 = alloca float, align 512
  %kernel_in_copy_0_4 = alloca float, align 512
  %kernel_in_copy_1_0 = alloca float, align 512
  %kernel_in_copy_1_1 = alloca float, align 512
  %kernel_in_copy_1_2 = alloca float, align 512
  %kernel_in_copy_1_3 = alloca float, align 512
  %kernel_in_copy_1_4 = alloca float, align 512
  %kernel_in_copy_2_0 = alloca float, align 512
  %kernel_in_copy_2_1 = alloca float, align 512
  %kernel_in_copy_2_2 = alloca float, align 512
  %kernel_in_copy_2_3 = alloca float, align 512
  %kernel_in_copy_2_4 = alloca float, align 512
  %kernel_in_copy_3_0 = alloca float, align 512
  %kernel_in_copy_3_1 = alloca float, align 512
  %kernel_in_copy_3_2 = alloca float, align 512
  %kernel_in_copy_3_3 = alloca float, align 512
  %kernel_in_copy_3_4 = alloca float, align 512
  %kernel_in_copy_4_0 = alloca float, align 512
  %kernel_in_copy_4_1 = alloca float, align 512
  %kernel_in_copy_4_2 = alloca float, align 512
  %kernel_in_copy_4_3 = alloca float, align 512
  %kernel_in_copy_4_4 = alloca float, align 512
  %0 = bitcast [5 x float]* %kernel_in to [5 x [5 x float]]*
  call void @copy_in(%"class.hls::stream"* %in_stream, i32* %in_stream_copy.data, i4* %in_stream_copy.keep, i4* %in_stream_copy.strb, i1* %in_stream_copy.user, i1* %in_stream_copy.last, i1* %in_stream_copy.id, i1* %in_stream_copy.dest, %"class.hls::stream"* %out_stream, i32* %out_stream_copy.data, i4* %out_stream_copy.keep, i4* %out_stream_copy.strb, i1* %out_stream_copy.user, i1* %out_stream_copy.last, i1* %out_stream_copy.id, i1* %out_stream_copy.dest, [5 x [5 x float]]* %0, float* nonnull align 512 %kernel_in_copy_0_0, float* nonnull align 512 %kernel_in_copy_0_1, float* nonnull align 512 %kernel_in_copy_0_2, float* nonnull align 512 %kernel_in_copy_0_3, float* nonnull align 512 %kernel_in_copy_0_4, float* nonnull align 512 %kernel_in_copy_1_0, float* nonnull align 512 %kernel_in_copy_1_1, float* nonnull align 512 %kernel_in_copy_1_2, float* nonnull align 512 %kernel_in_copy_1_3, float* nonnull align 512 %kernel_in_copy_1_4, float* nonnull align 512 %kernel_in_copy_2_0, float* nonnull align 512 %kernel_in_copy_2_1, float* nonnull align 512 %kernel_in_copy_2_2, float* nonnull align 512 %kernel_in_copy_2_3, float* nonnull align 512 %kernel_in_copy_2_4, float* nonnull align 512 %kernel_in_copy_3_0, float* nonnull align 512 %kernel_in_copy_3_1, float* nonnull align 512 %kernel_in_copy_3_2, float* nonnull align 512 %kernel_in_copy_3_3, float* nonnull align 512 %kernel_in_copy_3_4, float* nonnull align 512 %kernel_in_copy_4_0, float* nonnull align 512 %kernel_in_copy_4_1, float* nonnull align 512 %kernel_in_copy_4_2, float* nonnull align 512 %kernel_in_copy_4_3, float* nonnull align 512 %kernel_in_copy_4_4)
  call void @apatb_conv2d_hw(i32* %in_stream_copy.data, i4* %in_stream_copy.keep, i4* %in_stream_copy.strb, i1* %in_stream_copy.user, i1* %in_stream_copy.last, i1* %in_stream_copy.id, i1* %in_stream_copy.dest, i32* %out_stream_copy.data, i4* %out_stream_copy.keep, i4* %out_stream_copy.strb, i1* %out_stream_copy.user, i1* %out_stream_copy.last, i1* %out_stream_copy.id, i1* %out_stream_copy.dest, float* %kernel_in_copy_0_0, float* %kernel_in_copy_0_1, float* %kernel_in_copy_0_2, float* %kernel_in_copy_0_3, float* %kernel_in_copy_0_4, float* %kernel_in_copy_1_0, float* %kernel_in_copy_1_1, float* %kernel_in_copy_1_2, float* %kernel_in_copy_1_3, float* %kernel_in_copy_1_4, float* %kernel_in_copy_2_0, float* %kernel_in_copy_2_1, float* %kernel_in_copy_2_2, float* %kernel_in_copy_2_3, float* %kernel_in_copy_2_4, float* %kernel_in_copy_3_0, float* %kernel_in_copy_3_1, float* %kernel_in_copy_3_2, float* %kernel_in_copy_3_3, float* %kernel_in_copy_3_4, float* %kernel_in_copy_4_0, float* %kernel_in_copy_4_1, float* %kernel_in_copy_4_2, float* %kernel_in_copy_4_3, float* %kernel_in_copy_4_4, i32 %img_size)
  call void @copy_out(%"class.hls::stream"* %in_stream, i32* %in_stream_copy.data, i4* %in_stream_copy.keep, i4* %in_stream_copy.strb, i1* %in_stream_copy.user, i1* %in_stream_copy.last, i1* %in_stream_copy.id, i1* %in_stream_copy.dest, %"class.hls::stream"* %out_stream, i32* %out_stream_copy.data, i4* %out_stream_copy.keep, i4* %out_stream_copy.strb, i1* %out_stream_copy.user, i1* %out_stream_copy.last, i1* %out_stream_copy.id, i1* %out_stream_copy.dest, [5 x [5 x float]]* %0, float* nonnull align 512 %kernel_in_copy_0_0, float* nonnull align 512 %kernel_in_copy_0_1, float* nonnull align 512 %kernel_in_copy_0_2, float* nonnull align 512 %kernel_in_copy_0_3, float* nonnull align 512 %kernel_in_copy_0_4, float* nonnull align 512 %kernel_in_copy_1_0, float* nonnull align 512 %kernel_in_copy_1_1, float* nonnull align 512 %kernel_in_copy_1_2, float* nonnull align 512 %kernel_in_copy_1_3, float* nonnull align 512 %kernel_in_copy_1_4, float* nonnull align 512 %kernel_in_copy_2_0, float* nonnull align 512 %kernel_in_copy_2_1, float* nonnull align 512 %kernel_in_copy_2_2, float* nonnull align 512 %kernel_in_copy_2_3, float* nonnull align 512 %kernel_in_copy_2_4, float* nonnull align 512 %kernel_in_copy_3_0, float* nonnull align 512 %kernel_in_copy_3_1, float* nonnull align 512 %kernel_in_copy_3_2, float* nonnull align 512 %kernel_in_copy_3_3, float* nonnull align 512 %kernel_in_copy_3_4, float* nonnull align 512 %kernel_in_copy_4_0, float* nonnull align 512 %kernel_in_copy_4_1, float* nonnull align 512 %kernel_in_copy_4_2, float* nonnull align 512 %kernel_in_copy_4_3, float* nonnull align 512 %kernel_in_copy_4_4)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #1

; Function Attrs: nounwind
declare void @llvm.assume(i1) #2

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a5a5f32.9.10(float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4_4, [5 x [5 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1") #3 {
entry:
  %1 = icmp eq float* %_0_0, null
  %2 = icmp eq [5 x [5 x float]]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  %_0_01 = bitcast float* %_0_0 to i8*
  %_0_12 = bitcast float* %_0_1 to i8*
  %_0_23 = bitcast float* %_0_2 to i8*
  %_0_34 = bitcast float* %_0_3 to i8*
  %_0_45 = bitcast float* %_0_4 to i8*
  %_1_06 = bitcast float* %_1_0 to i8*
  %_1_17 = bitcast float* %_1_1 to i8*
  %_1_28 = bitcast float* %_1_2 to i8*
  %_1_39 = bitcast float* %_1_3 to i8*
  %_1_410 = bitcast float* %_1_4 to i8*
  %_2_011 = bitcast float* %_2_0 to i8*
  %_2_112 = bitcast float* %_2_1 to i8*
  %_2_213 = bitcast float* %_2_2 to i8*
  %_2_314 = bitcast float* %_2_3 to i8*
  %_2_415 = bitcast float* %_2_4 to i8*
  %_3_016 = bitcast float* %_3_0 to i8*
  %_3_117 = bitcast float* %_3_1 to i8*
  %_3_218 = bitcast float* %_3_2 to i8*
  %_3_319 = bitcast float* %_3_3 to i8*
  %_3_420 = bitcast float* %_3_4 to i8*
  %_4_021 = bitcast float* %_4_0 to i8*
  %_4_122 = bitcast float* %_4_1 to i8*
  %_4_223 = bitcast float* %_4_2 to i8*
  %_4_324 = bitcast float* %_4_3 to i8*
  %_4_425 = bitcast float* %_4_4 to i8*
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx12 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = icmp eq i64 %for.loop.idx12, 4
  br label %for.loop2

for.loop2:                                        ; preds = %.exit, %for.loop
  %for.loop.idx311 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %.exit ]
  %src.addr68.gep10 = getelementptr [5 x [5 x float]], [5 x [5 x float]]* %0, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %5 = bitcast float* %src.addr68.gep10 to i8*
  switch i64 %for.loop.idx12, label %.case.4 [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
  ]

.case.0:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.432 [
    i64 0, label %.case.028
    i64 1, label %.case.129
    i64 2, label %.case.230
    i64 3, label %.case.331
  ]

.case.028:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_0_01, i8* align 1 %5, i64 4, i1 false)
  br label %.exit27

.case.129:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_0_12, i8* align 1 %5, i64 4, i1 false)
  br label %.exit27

.case.230:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_0_23, i8* align 1 %5, i64 4, i1 false)
  br label %.exit27

.case.331:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_0_34, i8* align 1 %5, i64 4, i1 false)
  br label %.exit27

.case.432:                                        ; preds = %.case.0
  %6 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %6)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_0_45, i8* align 1 %5, i64 4, i1 false)
  br label %.exit27

.exit27:                                          ; preds = %.case.432, %.case.331, %.case.230, %.case.129, %.case.028
  br label %.exit

.case.1:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.439 [
    i64 0, label %.case.035
    i64 1, label %.case.136
    i64 2, label %.case.237
    i64 3, label %.case.338
  ]

.case.035:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_1_06, i8* align 1 %5, i64 4, i1 false)
  br label %.exit34

.case.136:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_1_17, i8* align 1 %5, i64 4, i1 false)
  br label %.exit34

.case.237:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_1_28, i8* align 1 %5, i64 4, i1 false)
  br label %.exit34

.case.338:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_1_39, i8* align 1 %5, i64 4, i1 false)
  br label %.exit34

.case.439:                                        ; preds = %.case.1
  %7 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %7)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_1_410, i8* align 1 %5, i64 4, i1 false)
  br label %.exit34

.exit34:                                          ; preds = %.case.439, %.case.338, %.case.237, %.case.136, %.case.035
  br label %.exit

.case.2:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.446 [
    i64 0, label %.case.042
    i64 1, label %.case.143
    i64 2, label %.case.244
    i64 3, label %.case.345
  ]

.case.042:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_2_011, i8* align 1 %5, i64 4, i1 false)
  br label %.exit41

.case.143:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_2_112, i8* align 1 %5, i64 4, i1 false)
  br label %.exit41

.case.244:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_2_213, i8* align 1 %5, i64 4, i1 false)
  br label %.exit41

.case.345:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_2_314, i8* align 1 %5, i64 4, i1 false)
  br label %.exit41

.case.446:                                        ; preds = %.case.2
  %8 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %8)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_2_415, i8* align 1 %5, i64 4, i1 false)
  br label %.exit41

.exit41:                                          ; preds = %.case.446, %.case.345, %.case.244, %.case.143, %.case.042
  br label %.exit

.case.3:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.453 [
    i64 0, label %.case.049
    i64 1, label %.case.150
    i64 2, label %.case.251
    i64 3, label %.case.352
  ]

.case.049:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_3_016, i8* align 1 %5, i64 4, i1 false)
  br label %.exit48

.case.150:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_3_117, i8* align 1 %5, i64 4, i1 false)
  br label %.exit48

.case.251:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_3_218, i8* align 1 %5, i64 4, i1 false)
  br label %.exit48

.case.352:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_3_319, i8* align 1 %5, i64 4, i1 false)
  br label %.exit48

.case.453:                                        ; preds = %.case.3
  %9 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %9)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_3_420, i8* align 1 %5, i64 4, i1 false)
  br label %.exit48

.exit48:                                          ; preds = %.case.453, %.case.352, %.case.251, %.case.150, %.case.049
  br label %.exit

.case.4:                                          ; preds = %for.loop2
  call void @llvm.assume(i1 %4)
  switch i64 %for.loop.idx311, label %.case.460 [
    i64 0, label %.case.056
    i64 1, label %.case.157
    i64 2, label %.case.258
    i64 3, label %.case.359
  ]

.case.056:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_4_021, i8* align 1 %5, i64 4, i1 false)
  br label %.exit55

.case.157:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_4_122, i8* align 1 %5, i64 4, i1 false)
  br label %.exit55

.case.258:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_4_223, i8* align 1 %5, i64 4, i1 false)
  br label %.exit55

.case.359:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_4_324, i8* align 1 %5, i64 4, i1 false)
  br label %.exit55

.case.460:                                        ; preds = %.case.4
  %10 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %10)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_4_425, i8* align 1 %5, i64 4, i1 false)
  br label %.exit55

.exit55:                                          ; preds = %.case.460, %.case.359, %.case.258, %.case.157, %.case.056
  br label %.exit

.exit:                                            ; preds = %.exit55, %.exit48, %.exit41, %.exit34, %.exit27
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx311, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 5
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx12, 1
  %exitcond13 = icmp ne i64 %for.loop.idx.next, 5
  br i1 %exitcond13, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @copy_in(%"class.hls::stream"* "orig.arg.no"="0", i32* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.0" %_V_data_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.1" %_V_keep_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.2" %_V_strb_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.3" %_V_user_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.4" %_V_last_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.5" %_V_id_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.6" %_V_dest_V, %"class.hls::stream"* "orig.arg.no"="2", i32* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.0" %_V_data_V1, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.1" %_V_keep_V2, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.2" %_V_strb_V3, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.3" %_V_user_V4, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.4" %_V_last_V5, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.5" %_V_id_V6, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.6" %_V_dest_V7, [5 x [5 x float]]* readonly "orig.arg.no"="4", float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_4, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_0, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_1, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_2, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_3, float* noalias align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_4) #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.29"(i32* %_V_data_V, i4* %_V_keep_V, i4* %_V_strb_V, i1* %_V_user_V, i1* %_V_last_V, i1* %_V_id_V, i1* %_V_dest_V, %"class.hls::stream"* %0)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.29"(i32* %_V_data_V1, i4* %_V_keep_V2, i4* %_V_strb_V3, i1* %_V_user_V4, i1* %_V_last_V5, i1* %_V_id_V6, i1* %_V_dest_V7, %"class.hls::stream"* %1)
  call void @onebyonecpy_hls.p0a5a5f32.9.10(float* align 512 %_0_0, float* align 512 %_0_1, float* align 512 %_0_2, float* align 512 %_0_3, float* align 512 %_0_4, float* align 512 %_1_0, float* align 512 %_1_1, float* align 512 %_1_2, float* align 512 %_1_3, float* align 512 %_1_4, float* align 512 %_2_0, float* align 512 %_2_1, float* align 512 %_2_2, float* align 512 %_2_3, float* align 512 %_2_4, float* align 512 %_3_0, float* align 512 %_3_1, float* align 512 %_3_2, float* align 512 %_3_3, float* align 512 %_3_4, float* align 512 %_4_0, float* align 512 %_4_1, float* align 512 %_4_2, float* align 512 %_4_3, float* align 512 %_4_4, [5 x [5 x float]]* %2)
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a5a5f32.15.16([5 x [5 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0", float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4_4) #3 {
entry:
  %1 = icmp eq [5 x [5 x float]]* %0, null
  %2 = icmp eq float* %_0_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  %_0_01 = bitcast float* %_0_0 to i8*
  %_0_12 = bitcast float* %_0_1 to i8*
  %_0_23 = bitcast float* %_0_2 to i8*
  %_0_34 = bitcast float* %_0_3 to i8*
  %_0_45 = bitcast float* %_0_4 to i8*
  %_1_06 = bitcast float* %_1_0 to i8*
  %_1_17 = bitcast float* %_1_1 to i8*
  %_1_28 = bitcast float* %_1_2 to i8*
  %_1_39 = bitcast float* %_1_3 to i8*
  %_1_410 = bitcast float* %_1_4 to i8*
  %_2_011 = bitcast float* %_2_0 to i8*
  %_2_112 = bitcast float* %_2_1 to i8*
  %_2_213 = bitcast float* %_2_2 to i8*
  %_2_314 = bitcast float* %_2_3 to i8*
  %_2_415 = bitcast float* %_2_4 to i8*
  %_3_016 = bitcast float* %_3_0 to i8*
  %_3_117 = bitcast float* %_3_1 to i8*
  %_3_218 = bitcast float* %_3_2 to i8*
  %_3_319 = bitcast float* %_3_3 to i8*
  %_3_420 = bitcast float* %_3_4 to i8*
  %_4_021 = bitcast float* %_4_0 to i8*
  %_4_122 = bitcast float* %_4_1 to i8*
  %_4_223 = bitcast float* %_4_2 to i8*
  %_4_324 = bitcast float* %_4_3 to i8*
  %_4_425 = bitcast float* %_4_4 to i8*
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx12 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = icmp eq i64 %for.loop.idx12, 4
  br label %for.loop2

for.loop2:                                        ; preds = %.exit, %for.loop
  %for.loop.idx311 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %.exit ]
  %dst.addr57.gep9 = getelementptr [5 x [5 x float]], [5 x [5 x float]]* %0, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %5 = bitcast float* %dst.addr57.gep9 to i8*
  switch i64 %for.loop.idx12, label %.case.4 [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
  ]

.case.0:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.432 [
    i64 0, label %.case.028
    i64 1, label %.case.129
    i64 2, label %.case.230
    i64 3, label %.case.331
  ]

.case.028:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_0_01, i64 4, i1 false)
  br label %.exit27

.case.129:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_0_12, i64 4, i1 false)
  br label %.exit27

.case.230:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_0_23, i64 4, i1 false)
  br label %.exit27

.case.331:                                        ; preds = %.case.0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_0_34, i64 4, i1 false)
  br label %.exit27

.case.432:                                        ; preds = %.case.0
  %6 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %6)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_0_45, i64 4, i1 false)
  br label %.exit27

.exit27:                                          ; preds = %.case.432, %.case.331, %.case.230, %.case.129, %.case.028
  br label %.exit

.case.1:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.439 [
    i64 0, label %.case.035
    i64 1, label %.case.136
    i64 2, label %.case.237
    i64 3, label %.case.338
  ]

.case.035:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_1_06, i64 4, i1 false)
  br label %.exit34

.case.136:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_1_17, i64 4, i1 false)
  br label %.exit34

.case.237:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_1_28, i64 4, i1 false)
  br label %.exit34

.case.338:                                        ; preds = %.case.1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_1_39, i64 4, i1 false)
  br label %.exit34

.case.439:                                        ; preds = %.case.1
  %7 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %7)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_1_410, i64 4, i1 false)
  br label %.exit34

.exit34:                                          ; preds = %.case.439, %.case.338, %.case.237, %.case.136, %.case.035
  br label %.exit

.case.2:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.446 [
    i64 0, label %.case.042
    i64 1, label %.case.143
    i64 2, label %.case.244
    i64 3, label %.case.345
  ]

.case.042:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_2_011, i64 4, i1 false)
  br label %.exit41

.case.143:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_2_112, i64 4, i1 false)
  br label %.exit41

.case.244:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_2_213, i64 4, i1 false)
  br label %.exit41

.case.345:                                        ; preds = %.case.2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_2_314, i64 4, i1 false)
  br label %.exit41

.case.446:                                        ; preds = %.case.2
  %8 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %8)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_2_415, i64 4, i1 false)
  br label %.exit41

.exit41:                                          ; preds = %.case.446, %.case.345, %.case.244, %.case.143, %.case.042
  br label %.exit

.case.3:                                          ; preds = %for.loop2
  switch i64 %for.loop.idx311, label %.case.453 [
    i64 0, label %.case.049
    i64 1, label %.case.150
    i64 2, label %.case.251
    i64 3, label %.case.352
  ]

.case.049:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_3_016, i64 4, i1 false)
  br label %.exit48

.case.150:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_3_117, i64 4, i1 false)
  br label %.exit48

.case.251:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_3_218, i64 4, i1 false)
  br label %.exit48

.case.352:                                        ; preds = %.case.3
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_3_319, i64 4, i1 false)
  br label %.exit48

.case.453:                                        ; preds = %.case.3
  %9 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %9)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_3_420, i64 4, i1 false)
  br label %.exit48

.exit48:                                          ; preds = %.case.453, %.case.352, %.case.251, %.case.150, %.case.049
  br label %.exit

.case.4:                                          ; preds = %for.loop2
  call void @llvm.assume(i1 %4)
  switch i64 %for.loop.idx311, label %.case.460 [
    i64 0, label %.case.056
    i64 1, label %.case.157
    i64 2, label %.case.258
    i64 3, label %.case.359
  ]

.case.056:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_4_021, i64 4, i1 false)
  br label %.exit55

.case.157:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_4_122, i64 4, i1 false)
  br label %.exit55

.case.258:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_4_223, i64 4, i1 false)
  br label %.exit55

.case.359:                                        ; preds = %.case.4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_4_324, i64 4, i1 false)
  br label %.exit55

.case.460:                                        ; preds = %.case.4
  %10 = icmp eq i64 %for.loop.idx311, 4
  call void @llvm.assume(i1 %10)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %_4_425, i64 4, i1 false)
  br label %.exit55

.exit55:                                          ; preds = %.case.460, %.case.359, %.case.258, %.case.157, %.case.056
  br label %.exit

.exit:                                            ; preds = %.exit55, %.exit48, %.exit41, %.exit34, %.exit27
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx311, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 5
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx12, 1
  %exitcond13 = icmp ne i64 %for.loop.idx.next, 5
  br i1 %exitcond13, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @copy_out(%"class.hls::stream"* "orig.arg.no"="0", i32* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.0" %_V_data_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.1" %_V_keep_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.2" %_V_strb_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.3" %_V_user_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.4" %_V_last_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.5" %_V_id_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" "unpacked"="1.6" %_V_dest_V, %"class.hls::stream"* "orig.arg.no"="2", i32* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.0" %_V_data_V1, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.1" %_V_keep_V2, i4* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.2" %_V_strb_V3, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.3" %_V_user_V4, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.4" %_V_last_V5, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.5" %_V_id_V6, i1* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="3" "unpacked"="3.6" %_V_dest_V7, [5 x [5 x float]]* "orig.arg.no"="4", float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_0_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_1_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_2_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_3_4, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_0, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_1, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_2, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_3, float* noalias readonly align 512 "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="5" %_4_4) #5 {
entry:
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* %0, i32* %_V_data_V, i4* %_V_keep_V, i4* %_V_strb_V, i1* %_V_user_V, i1* %_V_last_V, i1* %_V_id_V, i1* %_V_dest_V)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* %1, i32* %_V_data_V1, i4* %_V_keep_V2, i4* %_V_strb_V3, i1* %_V_user_V4, i1* %_V_last_V5, i1* %_V_id_V6, i1* %_V_dest_V7)
  call void @onebyonecpy_hls.p0a5a5f32.15.16([5 x [5 x float]]* %2, float* align 512 %_0_0, float* align 512 %_0_1, float* align 512 %_0_2, float* align 512 %_0_3, float* align 512 %_0_4, float* align 512 %_1_0, float* align 512 %_1_1, float* align 512 %_1_2, float* align 512 %_1_3, float* align 512 %_1_4, float* align 512 %_2_0, float* align 512 %_2_1, float* align 512 %_2_2, float* align 512 %_2_3, float* align 512 %_2_4, float* align 512 %_3_0, float* align 512 %_3_1, float* align 512 %_3_2, float* align 512 %_3_3, float* align 512 %_3_4, float* align 512 %_4_0, float* align 512 %_4_1, float* align 512 %_4_2, float* align 512 %_4_3, float* align 512 %_4_4)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* noalias align 512 "fpga.caller.interfaces"="layout_transformed", i32* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.0" %_V_data_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.1" %_V_keep_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.2" %_V_strb_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.3" %_V_user_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.4" %_V_last_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.5" %_V_id_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.6" %_V_dest_V) unnamed_addr #3 {
entry:
  %1 = icmp eq %"class.hls::stream"* %0, null
  %2 = or i1 %1, false
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream.24"(%"class.hls::stream"* nonnull align 512 %0, i32* %_V_data_V, i4* %_V_keep_V, i4* %_V_strb_V, i1* %_V_user_V, i1* %_V_last_V, i1* %_V_id_V, i1* %_V_dest_V)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @"streamcpy_hls.p0class.hls::stream.24"(%"class.hls::stream"* noalias nocapture align 512 "fpga.caller.interfaces"="layout_transformed", i32* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.0" %_V_data_V, i4* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.1" %_V_keep_V, i4* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.2" %_V_strb_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.3" %_V_user_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.4" %_V_last_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.5" %_V_id_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="1.6" %_V_dest_V) unnamed_addr #6 {
entry:
  %1 = alloca %"class.hls::stream"
  %2 = alloca i32
  %3 = alloca i4
  %4 = alloca i4
  %5 = alloca i1
  %6 = alloca i1
  %7 = alloca i1
  %8 = alloca i1
  br label %empty

empty:                                            ; preds = %push, %entry
  %9 = bitcast i32* %_V_data_V to i8*
  %10 = call i1 @fpga_fifo_not_empty_4(i8* %9)
  br i1 %10, label %push, label %ret

push:                                             ; preds = %empty
  %11 = bitcast i32* %2 to i8*
  %12 = bitcast i32* %_V_data_V to i8*
  call void @fpga_fifo_pop_4(i8* %11, i8* %12)
  %13 = load volatile i32, i32* %2
  %14 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 0
  %15 = bitcast %struct.ap_int* %14 to i32*
  store i32 %13, i32* %15
  %16 = bitcast i4* %4 to i8*
  %17 = bitcast i4* %_V_keep_V to i8*
  call void @fpga_fifo_pop_1(i8* %16, i8* %17)
  %18 = bitcast i4* %4 to i8*
  %19 = load i8, i8* %18
  %20 = trunc i8 %19 to i4
  %21 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1
  %22 = bitcast %struct.ap_uint* %21 to i4*
  store i4 %20, i4* %22
  %23 = bitcast i4* %3 to i8*
  %24 = bitcast i4* %_V_strb_V to i8*
  call void @fpga_fifo_pop_1(i8* %23, i8* %24)
  %25 = bitcast i4* %3 to i8*
  %26 = load i8, i8* %25
  %27 = trunc i8 %26 to i4
  %28 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2
  %29 = bitcast %struct.ap_uint* %28 to i4*
  store i4 %27, i4* %29
  %30 = bitcast i1* %8 to i8*
  %31 = bitcast i1* %_V_user_V to i8*
  call void @fpga_fifo_pop_1(i8* %30, i8* %31)
  %32 = bitcast i1* %8 to i8*
  %33 = load i8, i8* %32
  %34 = trunc i8 %33 to i1
  %35 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3
  %36 = bitcast %struct.ap_uint.2* %35 to i1*
  store i1 %34, i1* %36
  %37 = bitcast i1* %7 to i8*
  %38 = bitcast i1* %_V_last_V to i8*
  call void @fpga_fifo_pop_1(i8* %37, i8* %38)
  %39 = bitcast i1* %7 to i8*
  %40 = load i8, i8* %39
  %41 = trunc i8 %40 to i1
  %42 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4
  %43 = bitcast %struct.ap_uint.2* %42 to i1*
  store i1 %41, i1* %43
  %44 = bitcast i1* %6 to i8*
  %45 = bitcast i1* %_V_id_V to i8*
  call void @fpga_fifo_pop_1(i8* %44, i8* %45)
  %46 = bitcast i1* %6 to i8*
  %47 = load i8, i8* %46
  %48 = trunc i8 %47 to i1
  %49 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5
  %50 = bitcast %struct.ap_uint.2* %49 to i1*
  store i1 %48, i1* %50
  %51 = bitcast i1* %5 to i8*
  %52 = bitcast i1* %_V_dest_V to i8*
  call void @fpga_fifo_pop_1(i8* %51, i8* %52)
  %53 = bitcast i1* %5 to i8*
  %54 = load i8, i8* %53
  %55 = trunc i8 %54 to i1
  %56 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6
  %57 = bitcast %struct.ap_uint.2* %56 to i1*
  store i1 %55, i1* %57
  %58 = bitcast %"class.hls::stream"* %1 to i8*
  %59 = bitcast %"class.hls::stream"* %0 to i8*
  call void @fpga_fifo_push_12(i8* %58, i8* %59)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream.29"(i32* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.0" %_V_data_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.1" %_V_keep_V, i4* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.2" %_V_strb_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.3" %_V_user_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.4" %_V_last_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.5" %_V_id_V, i1* noalias "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.6" %_V_dest_V, %"class.hls::stream"* noalias "fpga.caller.interfaces"="layout_transformed") unnamed_addr #3 {
entry:
  %1 = icmp eq %"class.hls::stream"* %0, null
  %2 = or i1 false, %1
  br i1 %2, label %ret, label %copy

copy:                                             ; preds = %entry
  call fastcc void @"streamcpy_hls.p0class.hls::stream.32"(i32* %_V_data_V, i4* %_V_keep_V, i4* %_V_strb_V, i1* %_V_user_V, i1* %_V_last_V, i1* %_V_id_V, i1* %_V_dest_V, %"class.hls::stream"* nonnull %0)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @"streamcpy_hls.p0class.hls::stream.32"(i32* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.0" %_V_data_V, i4* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.1" %_V_keep_V, i4* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.2" %_V_strb_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.3" %_V_user_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.4" %_V_last_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.5" %_V_id_V, i1* noalias nocapture "fpga.caller.interfaces"="layout_transformed" "unpacked"="0.6" %_V_dest_V, %"class.hls::stream"* noalias nocapture "fpga.caller.interfaces"="layout_transformed") unnamed_addr #6 {
entry:
  %1 = alloca %"class.hls::stream"
  %2 = alloca %"class.hls::stream"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream"* %0 to i8*
  %4 = call i1 @fpga_fifo_not_empty_12(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream"* %2 to i8*
  %6 = bitcast %"class.hls::stream"* %0 to i8*
  call void @fpga_fifo_pop_12(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream", %"class.hls::stream"* %2
  store %"class.hls::stream" %7, %"class.hls::stream"* %1
  %8 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 0
  %9 = bitcast %struct.ap_int* %8 to i32*
  %10 = bitcast i32* %9 to i8*
  %11 = bitcast i32* %_V_data_V to i8*
  call void @fpga_fifo_push_4(i8* %10, i8* %11)
  %12 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1
  %13 = bitcast %struct.ap_uint* %12 to i4*
  %14 = bitcast i4* %13 to i8*
  %15 = bitcast i4* %_V_keep_V to i8*
  call void @fpga_fifo_push_1(i8* %14, i8* %15)
  %16 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2
  %17 = bitcast %struct.ap_uint* %16 to i4*
  %18 = bitcast i4* %17 to i8*
  %19 = bitcast i4* %_V_strb_V to i8*
  call void @fpga_fifo_push_1(i8* %18, i8* %19)
  %20 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3
  %21 = bitcast %struct.ap_uint.2* %20 to i1*
  %22 = bitcast i1* %21 to i8*
  %23 = bitcast i1* %_V_user_V to i8*
  call void @fpga_fifo_push_1(i8* %22, i8* %23)
  %24 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4
  %25 = bitcast %struct.ap_uint.2* %24 to i1*
  %26 = bitcast i1* %25 to i8*
  %27 = bitcast i1* %_V_last_V to i8*
  call void @fpga_fifo_push_1(i8* %26, i8* %27)
  %28 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5
  %29 = bitcast %struct.ap_uint.2* %28 to i1*
  %30 = bitcast i1* %29 to i8*
  %31 = bitcast i1* %_V_id_V to i8*
  call void @fpga_fifo_push_1(i8* %30, i8* %31)
  %32 = getelementptr inbounds %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6
  %33 = bitcast %struct.ap_uint.2* %32 to i1*
  %34 = bitcast i1* %33 to i8*
  %35 = bitcast i1* %_V_dest_V to i8*
  call void @fpga_fifo_push_1(i8* %34, i8* %35)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  ret void
}

declare void @apatb_conv2d_hw(i32*, i4*, i4*, i1*, i1*, i1*, i1*, i32*, i4*, i4*, i1*, i1*, i1*, i1*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, i32)

define void @conv2d_hw_stub_wrapper(i32*, i4*, i4*, i1*, i1*, i1*, i1*, i32*, i4*, i4*, i1*, i1*, i1*, i1*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, i32) #7 {
entry:
  %40 = alloca %"class.hls::stream"
  %41 = alloca %"class.hls::stream"
  %42 = alloca [5 x [5 x float]]
  call void @copy_out(%"class.hls::stream"* %40, i32* %0, i4* %1, i4* %2, i1* %3, i1* %4, i1* %5, i1* %6, %"class.hls::stream"* %41, i32* %7, i4* %8, i4* %9, i1* %10, i1* %11, i1* %12, i1* %13, [5 x [5 x float]]* %42, float* %14, float* %15, float* %16, float* %17, float* %18, float* %19, float* %20, float* %21, float* %22, float* %23, float* %24, float* %25, float* %26, float* %27, float* %28, float* %29, float* %30, float* %31, float* %32, float* %33, float* %34, float* %35, float* %36, float* %37, float* %38)
  %43 = bitcast [5 x [5 x float]]* %42 to [5 x float]*
  call void @conv2d_hw_stub(%"class.hls::stream"* %40, %"class.hls::stream"* %41, [5 x float]* %43, i32 %39)
  call void @copy_in(%"class.hls::stream"* %40, i32* %0, i4* %1, i4* %2, i1* %3, i1* %4, i1* %5, i1* %6, %"class.hls::stream"* %41, i32* %7, i4* %8, i4* %9, i1* %10, i1* %11, i1* %12, i1* %13, [5 x [5 x float]]* %42, float* %14, float* %15, float* %16, float* %17, float* %18, float* %19, float* %20, float* %21, float* %22, float* %23, float* %24, float* %25, float* %26, float* %27, float* %28, float* %29, float* %30, float* %31, float* %32, float* %33, float* %34, float* %35, float* %36, float* %37, float* %38)
  ret void
}

declare void @conv2d_hw_stub(%"class.hls::stream"*, %"class.hls::stream"*, [5 x float]*, i32)

declare i1 @fpga_fifo_not_empty_12(i8*)

declare i1 @fpga_fifo_not_empty_4(i8*)

declare void @fpga_fifo_pop_12(i8*, i8*)

declare void @fpga_fifo_pop_4(i8*, i8*)

declare void @fpga_fifo_pop_1(i8*, i8*)

declare void @fpga_fifo_push_12(i8*, i8*)

declare void @fpga_fifo_push_4(i8*, i8*)

declare void @fpga_fifo_push_1(i8*, i8*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind }
attributes #3 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { argmemonly noinline "fpga.wrapper.func"="copyin" }
attributes #5 = { argmemonly noinline "fpga.wrapper.func"="copyout" }
attributes #6 = { argmemonly noinline "fpga.wrapper.func"="streamcpy_hls" }
attributes #7 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.rotate.disable"}
