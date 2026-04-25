### Finding positional min & max

import torch

x = torch.arange(5, 50, 5)  # 5 -> 45 (jump 5)
print("Original:\t\t", x)

## Find the position in tensor that has the minimum value with argmin() -> returns index position of target tensor where the min value occurs
print("Pos with min value:\t", torch.argmin(x))

## Find the position in tensor that has the maximum value with argmax()
print("Pos with max value:\t", torch.argmax(x))