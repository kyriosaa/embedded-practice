### Matrix manipulation

# Two main ways of performing multiplication in neural networks and deep learning:
# 1. Element-wise multiplication
# 2. Matrix multiplication / dot product (probably most common in neural networks)

import torch

matrix1 = torch.tensor([[1, 2, 3],
                        [4, 5, 6]])
matrix2 = torch.tensor([[7, 8],
                        [9, 10],
                        [11, 12]])
mul_matrix = torch.matmul(matrix1, matrix2)
print(mul_matrix)

### Be careful of shape errors! 