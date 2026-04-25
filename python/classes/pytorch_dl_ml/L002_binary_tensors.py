### Zeroes and Ones

import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# create a tensor of all zeroes
# (good for clearing out tensors)
zeroes_tensor = torch.zeros(3, 4)
print(zeroes_tensor)
print("\n")

# create a tensor of all ones
# (less common than zeroes but still relevant)
ones_tensor = torch.ones(3, 4)
print(ones_tensor)
print("\n")

# clearing out a random tensor
random_tensor = torch.rand(3, 4)
print(random_tensor)
print("\n")
print(random_tensor*zeroes_tensor)