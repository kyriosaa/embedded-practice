# intro to tensors

import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
# print(torch.__version__)

# PyTorch tensors are created using `torch.Tensor()` -= https://pytorch.org/docs/stable/tensors.html


# scalar
scalar = torch.tensor(7)
print(scalar)           # prints the tensor value
print(scalar.ndim)      # prints the tensor dimension (scalar has 0)
print(scalar.item)      # prints the tensor value as item
print("\n")


# vector
vector = torch.tensor([7, 7])
print(vector.ndim)      # ez way to remember is that dimension counts the pairs of brackets in a tensor
print(vector.shape)     # shape considers how many numbers
print("\n")


# MATRIX
MATRIX = torch.tensor([[7, 8], 
                       [9, 10]])
print(MATRIX)
print(MATRIX.ndim)
print(MATRIX[0])
print(MATRIX.shape)     # 2x2
print("\n")


# TENSOR
TENSOR = torch.tensor([[[1, 2, 3],
                        [3, 6, 9],
                        [2, 4, 5]]])
print(TENSOR)
print(TENSOR.ndim)
print(TENSOR.shape)
print(TENSOR[0])