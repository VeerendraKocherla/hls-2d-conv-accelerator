#include <stdio.h>

#define INP_SIZE 64
#define KERNEL_SIZE 3

#include "kernel.h"

// Top function for HLS
void conv2d(
    float input[INP_SIZE][INP_SIZE],
    float output[INP_SIZE][INP_SIZE]
) {

    int pad = KERNEL_SIZE / 2;

    // Iterate over output
    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {

            float sum = 0.0f;

            // Kernel loop
            for (int m = 0; m < KERNEL_SIZE; m++) {
                for (int n = 0; n < KERNEL_SIZE; n++) {


                    int ii = i + m - pad;
                    int jj = j + n - pad;

                    // Zero padding
                    if (ii >= 0 && ii < INP_SIZE &&
                        jj >= 0 && jj < INP_SIZE) {

                        // IMPORTANT: flip kernel for convolution
                        float k = kernel[KERNEL_SIZE - 1 - m][KERNEL_SIZE - 1 - n];
                        float val = input[ii][jj];

                        sum += val * k;
                    }
                }
            }

            output[i][j] = sum;
        }
    }
}
