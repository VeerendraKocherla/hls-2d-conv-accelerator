############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_pipeline "conv2d"
set_directive_array_partition -type complete -dim 0 "conv2d" kernel_in
set_directive_allocation -type operation -limit 1 "conv2d" mul
set_directive_allocation -type operation -limit 1 "conv2d" add
set_directive_top -name conv2d "conv2d"
set_directive_array_partition -dim 0 -type complete "conv2d" kernel_in
set_directive_allocation -limit 1 -type operation "conv2d/COL_SLIDE" mul
set_directive_allocation -limit 1 -type operation "conv2d/COL_SLIDE" add
