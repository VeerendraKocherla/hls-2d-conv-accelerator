import numpy as np
from scipy.ndimage import convolve

input_file = "input.txt"
# kernel_file = "kernel.h"
kernel_file = "kernel.txt"
out_file = "expected_output.txt"

inp_size = 128
kernel_size = 5

inp = np.random.randint(low=0, high=255, size=(inp_size, inp_size))/255
kernel = np.random.uniform(-1, 1, (kernel_size, kernel_size))

out = convolve(inp, kernel, mode='constant', cval=0.0)

with open(input_file, 'w') as f:
    for row in inp:
        for ele in row:
            f.write(str(ele) + '\n')

with open(kernel_file, 'w') as f:
    # f.write(f"#ifndef KERNEL_H\n#define KENREL_H\n")
    # f.write(f"#define kernel_size {kernel_size}\n\n")
    # f.write("static const float kernel[kernel_size][kernel_size] = {\n")
    for row in kernel:
        for ele in row:
            f.write(str(ele) + '\n')
    # f.write('};\n#endif')

with open(out_file, 'w') as f:
    for row in out:
        for ele in row:
            f.write(str(ele) + '\n')
