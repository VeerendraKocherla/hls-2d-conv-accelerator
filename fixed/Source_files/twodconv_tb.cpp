#include "twodconv.h" 
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 

#define IMG_SIZE 64
#define TOLERANCE 1e-2

static int read_vector(const char *fname, float *buf, int max_n) {
    FILE *f = fopen(fname, "r");
    if (!f) { fprintf(stderr, "Cannot open %s\n", fname); exit(1); }
    int n = 0;
    while (n < max_n && fscanf(f, "%f", &buf[n]) == 1) n++;
    fclose(f);
    return n;
}

int main() {
    int MAX_SAMPLES = IMG_SIZE * IMG_SIZE;

    float input[MAX_SAMPLES], expected[MAX_SAMPLES];
    float kernel[kernel_size][kernel_size];

    int n_in  = read_vector("input.txt", input, MAX_SAMPLES);
    int n_ker = read_vector("kernel.txt", &kernel[0][0], kernel_size * kernel_size);
    int n_exp = read_vector("expected_output.txt", expected, MAX_SAMPLES);

    if (n_in != MAX_SAMPLES || n_exp != MAX_SAMPLES) {
        printf("FAIL: mismatched vector lengths (Read In: %d, Read Exp: %d)\n", n_in, n_exp);
        return 1;
    }

    hls::stream<axis_pkt_t> in_stream("in");
    hls::stream<axis_pkt_t> out_stream("out");

    /* Pack input into AXI-Stream packets */
    for (int i = 0; i < n_in; i++) {
        axis_pkt_t pkt;

        data_t fixed_val = (data_t) input[i];
        pkt.data.range(15, 0) = fixed_val.range();

        pkt.keep = -1;
        pkt.strb = -1;
        pkt.user = 0;
        pkt.id   = 0;
        pkt.dest = 0;
        pkt.last = (i == n_in - 1) ? 1 : 0;

        in_stream.write(pkt);
    }

    /* Convert kernel to fixed-point */
    data_t kernel_fixed[kernel_size][kernel_size];
    for (int k1 = 0; k1 < kernel_size; k1++) {
        for (int k2 = 0; k2 < kernel_size; k2++) {
            kernel_fixed[k1][k2] = (data_t) kernel[k1][k2];
        }
    }

    /* Run convolution */
    conv2d(in_stream, out_stream, kernel_fixed, IMG_SIZE);

    /* Open output file */
    FILE *fout = fopen("computed_output.txt", "w");
    if (!fout) {
        printf("ERROR: cannot open computed_output.txt\n");
        return 1;
    }

    int errors = 0;
    float y;

    for (int i = 0; i < n_exp; i++) {
        axis_pkt_t pkt = out_stream.read();

        data_t fixed_out;
        fixed_out.range() = pkt.data.range(15, 0);
        y = (float) fixed_out;

        /* Write computed output */
        fprintf(fout, "%.6f\n", y);

        float err = std::abs(y - expected[i]);

        if (err > TOLERANCE) {
            printf("MISMATCH at sample %d: got %.6f, expected %.6f (err=%.6e)\n",
                   i, y, expected[i], err);
            // Uncomment if you want strict fail counting
             errors++;
        }
    }

    fclose(fout);

    if (errors == 0)
        printf("PASS: %d samples matched (tolerance=%.0e)\n", n_exp, TOLERANCE);
    else
        printf("FAIL: %d / %d mismatches\n", errors, n_exp);

    return errors ? 1 : 0;
}
