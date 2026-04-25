### Running Tensors and PyTorch objects on a GPU

## Thanks to CUDA + NVIDIA hardware, we can make faster computations

import torch

# check for GPU access with PyTorch
print(torch.cuda.is_available())

## Since PyTorch can make computations on both CPU and GPU, its best practice to set up device-agnostic code

# setup device agnostic code
device = "cuda" if torch.cuda.is_available() else "cpu"
print(device)

# count number of devices
print(torch.cuda.device_count())