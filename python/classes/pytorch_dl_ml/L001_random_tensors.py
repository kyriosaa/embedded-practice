### Random Tensors

# Random tensors are important because the way many neural networks learn is that they start with tensors full of random numbers
# and then adjust those random numbers to better represent the data.
# Start w random numbers -> look at data -> update random numbers -> look at data -> update random numbers

import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# create random tensors
random_tensor = torch.rand(3, 4) # 2 dimensions
print(random_tensor, "\n\n")

random_tensor = torch.rand(2, 3, 4) # 3 dimensions
print(random_tensor, "\n\n")

random_tensor = torch.rand(2, 2, 3, 4) # 4 dimensions
print(random_tensor, "\n\n")

# create random tensor with similar shape to an image tensor
random_image_size_tensor = torch.rand(size=(224, 224, 3)) # height, width, color channels (RGB) ; the size=() usage is optional
print(random_image_size_tensor.shape, random_image_size_tensor.ndim)