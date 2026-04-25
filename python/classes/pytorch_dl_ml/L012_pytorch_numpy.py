### PyTorch tensors and NumPy

## NumPy is a popular scientific Python numerical computing library.
## Because of this, PyTorch has the functionality to interact with it.

## * Data in NumPy, want in PyTorch tensor -> `torch.from_numpy(ndarray)`
## * PyTorch tensor, want in NumPy -> `torch.Tensor.numpy()` 

import torch
import numpy as np

# NumPy array to tensor
array = np.arange(1.0, 8.0)
tensor = torch.from_numpy(array)
print(array)    # [1. 2. 3. 4. 5. 6. 7.]
print(tensor)   # tensor([1., 2., 3., 4., 5., 6., 7.], dtype=torch.float64) // NumPy's default datatype is float64 - PyTorch is float32
print("\n")

# Change the value of array, what will this do to `tensor`?
array = array + 1
print(array, tensor)    # changing the array does not change `tensor` beacuse a new value is created in memory
print("\n")

# Tensor to NumPy array
tensor = torch.ones(7)
numpy_tensor = tensor.numpy()
print(tensor, numpy_tensor)
print("\n")

# Change the tensor, what happens to `numpy_tensor`?
tensor = tensor + 1
print(tensor, numpy_tensor)     # again, these variables do not share memory so changing one does not change the other
print("\n")