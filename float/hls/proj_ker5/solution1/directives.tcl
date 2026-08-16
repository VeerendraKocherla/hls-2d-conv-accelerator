############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_top -name conv2d "conv2d"
set_directive_pipeline -II 1 "conv2d/COL_SLIDE"
set_directive_array_partition -type complete -dim 0 "conv2d" kernel_in
