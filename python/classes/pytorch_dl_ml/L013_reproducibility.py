### Reproducibility - trying to take the random out of random

## In short, how a neural network learns is by:
# start with random numbers -> 
# tensor operations -> 
# update random numbers to try and make better representations of the data -> 
# again -> 
# again...

# To reduce the randomness in neural networks and PyTorch comes the concept of a **random seed**
# (it essentially "flavors" the randomness)

import torch

# Create two random tensors
rand_tensor_A = torch.rand(3, 4)
rand_tensor_B = torch.rand(3, 4)

print(rand_tensor_A)
print(rand_tensor_B)
print(rand_tensor_A == rand_tensor_B)   # highly unlinkely that any will return true
print("\n")


# Let's make some random but reproducible tensors
RANDOM_SEED = 1234

torch.manual_seed(RANDOM_SEED)      # torch.manual_seed() generally only works for one block of code and needs rewriting everytime we use it
rand_tensor_C = torch.rand(3, 4)

torch.manual_seed(RANDOM_SEED)      # torch.manual_seed() generally only works for one block of code and needs rewriting everytime we use it
rand_tensor_D = torch.rand(3, 4)

print(rand_tensor_C)
print(rand_tensor_D)
print(rand_tensor_C == rand_tensor_D)
print("\n")

# https://docs.pytorch.org/docs/stable/notes/randomness.html