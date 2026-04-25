### Range of tensors and tensors-like

import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# simple range
one_to_ten = torch.arange(1, 11)
print(one_to_ten)

# range using start, end, and step
step = torch.arange(start=0, end=1000, step=77)
print(step)

# creating tensors-like

# created a tensor of only zeros with a "template" of the one_to_ten tensor
ten_zeros = torch.zeros_like(input=one_to_ten)
print(ten_zeros)
# created a tensor of only zeros with a "template" of the step tensor
step_zeros = torch.zeros_like(input=step)
print(step_zeros)