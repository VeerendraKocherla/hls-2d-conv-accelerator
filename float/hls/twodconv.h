#ifndef TWODCONV_H
#define TWODCONV_H

#include "common.h"
#include <hls_stream.h>
#include <ap_axi_sdata.h>

typedef ap_axis<32, 1, 1, 1> axis_pkt_t;
#define MAX_IMG_WIDTH 256
#define kernel_size 3

void conv2d(hls::stream<axis_pkt_t> &in_stream,
            hls::stream<axis_pkt_t> &out_stream,
            data_t kernel_in[kernel_size][kernel_size],
            int img_size);

#endif
