<<<<<<< HEAD
#include <stdio.h>

#define INP_SIZE 64
#define KERNEL_SIZE 3

#include "kernel.h"

void conv2d(
    float input[INP_SIZE][INP_SIZE],
    float output[INP_SIZE][INP_SIZE]
) {
    int pad = KERNEL_SIZE / 2;

    // Output loops
    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {

            float sum = 0.0f;

            // Flattened kernel loop
            for (int k = 0; k < KERNEL_SIZE * KERNEL_SIZE; k++) {

                int m = k / KERNEL_SIZE;
                int n = k % KERNEL_SIZE;

                int ii = i + m - pad;
                int jj = j + n - pad;

                // Zero padding check
                if (ii >= 0 && ii < INP_SIZE &&
                    jj >= 0 && jj < INP_SIZE) {

                    float kval = kernel[KERNEL_SIZE - 1 - m][KERNEL_SIZE - 1 - n];
                    float val  = input[ii][jj];

                    sum += val * kval;
                }
            }

            output[i][j] = sum;
        }
    }
=======
#include <stdio.h>

#define INP_SIZE 64
#define KERNEL_SIZE 3

#include "kernel.h"

void conv2d(
    float input[INP_SIZE][INP_SIZE],
    float output[INP_SIZE][INP_SIZE]
) {
    int pad = KERNEL_SIZE / 2;

    // Output loops
    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {

            float sum = 0.0f;

            // Flattened kernel loop
            for (int k = 0; k < KERNEL_SIZE * KERNEL_SIZE; k++) {

                int m = k / KERNEL_SIZE;
                int n = k % KERNEL_SIZE;

                int ii = i + m - pad;
                int jj = j + n - pad;

                // Zero padding check
                if (ii >= 0 && ii < INP_SIZE &&
                    jj >= 0 && jj < INP_SIZE) {

                    float kval = kernel[KERNEL_SIZE - 1 - m][KERNEL_SIZE - 1 - n];
                    float val  = input[ii][jj];

                    sum += val * kval;
                }
            }

            output[i][j] = sum;
        }
    }
>>>>>>> 22baf4992d9824e105af74af0b4534b8205b5ac0
}