### Reshaping, stacking, squeezing, and unsqueezing tensors

# Reshaping     reshapes an input tensor to a defined shape
# View          return a view of an input tensor of certain shape but keep the same memory as the original tensor
# Stacking      combine multiple tensors on top of each other (vstack) or side-by-side (hstack)
# Squeeze       removes all `1` dimensions from a tensor
# Unsqueeze     add a `1` dimension to a target tensor
# Permute       return a view of the input with dimensions permuted (swapped) in a certain way

import torch

x = torch.arange(0., 10.)   # make it a float with the .
print("Original Tensor:\t", x)
print("Original Shape:\t\t", x.shape)
print("\n")

# Add an extra dimension - needs to be compatible with the original size
x_reshaped = x.reshape(5, 2) # 5*2=10 so its compatible with the original tensor
print(x_reshaped.shape)
print(x_reshaped)

# Change the view
y = x.view(1, 10)
print(y)
print(y.shape)
# Changing y also changes x because a view of a tensor shares the same memory as the original tensor
y[:, 0] = 5
print(y)
print(x)

# Stack tensors on top of each other
x_stacked = torch.stack([x, x, x, x], dim=0)
print(x_stacked)

# Squeeze tensors - remove all single dimensions from a target tensor
print(x_reshaped)
print(x_reshaped.shape)
print(x_reshaped.squeeze())

# Unsqueeze tensors - adds a single dimension to a target tensor at a specific dimension
print(x_reshaped)
print(x_reshaped.shape)
x_unsqueezed = x_reshaped.unsqueeze(dim=0)
print(x_unsqueezed)
print(x_unsqueezed.shape)

# Permute tensors - rearranges the dimensions of a target tensor in a specified order
x_original = torch.rand(size=(224, 224, 3)) # height, width, color channels (img data)
print(x_original)
# permute x_original to rearrange the dimension order
x_permuted = x_original.permute(2, 0, 1)
print(x_permuted)