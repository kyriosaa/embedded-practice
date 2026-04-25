### Tensor attributes

# 1. Tensors not right datatype - to get datatype from a tensor, use `tensor.dtype`
# 2. Tensors not right shape - to get shape from a tensor, use `tensor.shape`
# 3. Tensors not on the right device - to get device from a tensor, use `tensor.device`

import torch

some_tensor = torch.rand(dtype=torch.float64, size=[3, 4], device="cuda")
print(some_tensor)

# find out details abt tensor
print(f"Datatype of tensor: {some_tensor.dtype}")
print(f"Shape of tensor: {some_tensor.shape}")
print(f"Device of tensor: {some_tensor.device}")