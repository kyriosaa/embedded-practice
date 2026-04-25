### Putting tensors (and models) on GPU because it gives faster computations

import torch

# create tensor
tensor = torch.tensor([1, 2, 3])

# tensor not on GPU
print(tensor)
print(tensor.device)    # its on cpu

# move tensor to GPU if available
device = "cuda" if torch.cuda.is_available() else "cpu"
tensor_gpu = tensor.to(device)
print(tensor_gpu)
print(tensor_gpu.device)

### Move tensor back to CPU
# if tensor is on GPU, we can't transform it to NumPy
# tensor_gpu.numpy() # doesnt work
tensor_back_cpu = tensor_gpu.cpu().numpy()
print(tensor_back_cpu)