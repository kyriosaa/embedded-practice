### Tensor datatypes

# Tensor datatypes is one of the 3 big common errors with PyTorch and deep learning
# 1. Tensors not right datatype
# 2. Tensors not right shape
# 3. Tensors not on the right device

import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# float 32 tensor
float_32_tensor = torch.tensor([3.0, 6.0, 9.0],
                               dtype=torch.float32,     # what datatype is the tensor (float32 / float16)
                               device="cuda",           # what device is tensor on
                               requires_grad=False)     # gradient tracking
print(float_32_tensor)
print(float_32_tensor.dtype)
print("\n")

# float 16 tensor
float_16_tensor = float_32_tensor.type(torch.float16)
print(float_16_tensor)
print("\n")

print("16x32\n", float_16_tensor * float_32_tensor)

# rand float 32 tensor
rand_32_tensor = torch.rand(2, 4, 3, 
                            dtype=torch.float32, 
                            device="cuda", 
                            requires_grad=False)
print(rand_32_tensor)
print("\n")

# int 32 tensor
int_32_tensor = torch.tensor([3, 6, 9],
                             dtype=torch.int32)
print(int_32_tensor)
print(int_32_tensor * float_32_tensor)  # int and float can still be calculated together