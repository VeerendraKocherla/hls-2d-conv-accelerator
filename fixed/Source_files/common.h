#ifndef COMMON_H
#define COMMON_H

/* ---- Choose one ---- */
//#define USE_FLOAT
#define USE_FIXED

#ifdef USE_FIXED
#include <ap_fixed.h>
typedef ap_fixed<16, 5> data_t;
#define DATA_WIDTH 16
#else
typedef float data_t;
#define DATA_WIDTH 32
#endif


#endif
