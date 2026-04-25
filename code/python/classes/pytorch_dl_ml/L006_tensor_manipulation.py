### Tensor manipulation

# Tensor operations include:
# Addition
# Subtraction
# Multiplication (element-wise)
# Division  
# Matrix multiplication

import torch

tensor = torch.tensor([1, 2, 3])

# math calculations with tensors
print(tensor + 10)  #[11, 12, 13]
print(tensor + 100) #[101, 102, 103]

print(tensor - 10)  #[-9, -8, -7]

print(tensor * 10)  #[10, 20, 30]


# PyTorch also has built-in functions (kinda like C's math.h)
print(torch.add(tensor, 10))
print(torch.add(tensor, 100))

print(torch.sub(tensor, 10))

print(torch.mul(tensor, 10))