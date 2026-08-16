<<<<<<< HEAD
#include <stdio.h>

#define INP_SIZE 64
#define KERNEL_SIZE 3
#define TOLERANCE 1e-3f

// DUT declaration
void conv2d(
    float input[INP_SIZE][INP_SIZE],
    float output[INP_SIZE][INP_SIZE]
);

int main() {
    float input[INP_SIZE][INP_SIZE];
    float output[INP_SIZE][INP_SIZE];
    float expected;

    FILE *fin  = fopen("input.txt", "r");
    FILE *fexp = fopen("expected_output.txt", "r");
    FILE *fout = fopen("hls_output.txt", "w");


    if (!fin || !fexp || !fout) {
        printf("Error opening files\n");
        return 1;
    }

    // Read input
    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {
            fscanf(fin, "%f", &input[i][j]);
        }
    }
    fclose(fin);

    // Run DUT
    conv2d(input, output);

    // Compare with expected
    int errors = 0;

    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {

            fscanf(fexp, "%f", &expected);

            float y = output[i][j];
            float err = (y > expected) ? (y - expected) : (expected - y);

            fprintf(fout, "%f\n", output[i][j]);

            if (err > TOLERANCE) {
                printf("MISMATCH at sample %d: got %.6f, expected %.6f (err=%.6e)\n",
                       i * INP_SIZE + j, y, expected, err);
                errors++;
            }
        }
    }

    fclose(fexp);
    fclose(fout);

    // Final result
    if (errors == 0) {
        printf("PASS\n");
        return 0;
    } else {
        printf("FAIL: %d mismatches\n", errors);
        return 1;
    }
}
=======
#include <stdio.h>

#define INP_SIZE 64
#define KERNEL_SIZE 3
#define TOLERANCE 1e-3f

// DUT declaration
void conv2d(
    float input[INP_SIZE][INP_SIZE],
    float output[INP_SIZE][INP_SIZE]
);

int main() {
    float input[INP_SIZE][INP_SIZE];
    float output[INP_SIZE][INP_SIZE];
    float expected;

    FILE *fin  = fopen("input.txt", "r");
    FILE *fexp = fopen("expected_output.txt", "r");
    FILE *fout = fopen("hls_output.txt", "w");


    if (!fin || !fexp || !fout) {
        printf("Error opening files\n");
        return 1;
    }

    // Read input
    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {
            fscanf(fin, "%f", &input[i][j]);
        }
    }
    fclose(fin);

    // Run DUT
    conv2d(input, output);

    // Compare with expected
    int errors = 0;

    for (int i = 0; i < INP_SIZE; i++) {
        for (int j = 0; j < INP_SIZE; j++) {

            fscanf(fexp, "%f", &expected);

            float y = output[i][j];
            float err = (y > expected) ? (y - expected) : (expected - y);

            fprintf(fout, "%f\n", output[i][j]);

            if (err > TOLERANCE) {
                printf("MISMATCH at sample %d: got %.6f, expected %.6f (err=%.6e)\n",
                       i * INP_SIZE + j, y, expected, err);
                errors++;
            }
        }
    }

    fclose(fexp);
    fclose(fout);

    // Final result
    if (errors == 0) {
        printf("PASS\n");
        return 0;
    } else {
        printf("FAIL: %d mismatches\n", errors);
        return 1;
    }
}
>>>>>>> 22baf4992d9824e105af74af0b4534b8205b5ac0
