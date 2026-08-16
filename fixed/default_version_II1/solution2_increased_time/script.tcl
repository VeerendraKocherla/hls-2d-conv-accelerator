############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project daniel_k3_II1
set_top conv2d
add_files twodconv.h
add_files twodconv.cpp
add_files common.h
add_files -tb twodconv_tb.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb kernel.txt -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb input.txt -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb expected_output.txt -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2_increased_time" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
set_clock_uncertainty 1.25
source "./daniel_k3_II1/solution2_increased_time/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
