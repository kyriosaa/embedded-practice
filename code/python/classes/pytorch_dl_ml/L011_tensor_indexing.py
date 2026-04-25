### Indexing (selecting data from tensors)

import torch

# Indexing with PyTorch is similar to indexing with NumPy

x = torch.arange(1, 10).reshape(1, 3, 3)
print(x)
print(x.shape, "\n")    # torch.Size([1, 3, 3]) /// torch.Size([1][3][3])

# Index on first bracket
print(f"Index on first bracket:\n {x[0]} \n")   # tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

# Index on second bracket
print(f"Index on second bracket:\n {x[0][0]} \n")   # tensor([1, 2, 3])

# Index on third bracket
print(f"Index on third bracket:\n {x[0][0][0]} \n")   # tensor(1)

# You can also use ":" to select "all" of a target dimension
print(x[:, 0])