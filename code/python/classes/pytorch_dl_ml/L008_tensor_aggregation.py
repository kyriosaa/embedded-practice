### Finding the min, max, mean, sum, etc (tensor aggregation)

import torch

x = torch.arange(0, 100, 10)
print("Original:\t", x)

## Find min
print("Min:\t\t", torch.min(x))

## Find max
print("Max:\t\t", torch.max(x))

## Find mean
# torch.mean(x)  !! Doesnt Work bcs x needs to be float (right now its long) !!
# torch.mean(x.type(torch.float32))
print("Mean:\t\t", torch.mean(x.type(torch.float32)))

## Find sum
print("Sum:\t\t", torch.sum(x))