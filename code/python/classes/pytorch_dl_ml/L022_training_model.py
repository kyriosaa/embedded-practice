from L021_making_predictions import *
import torch

# The whole idea of training is for a model to move from some *unknown* parameters (maybe random) to some *known* parameters.
#
# In other words, from a poor representation of the data to a better representation of the data.
#
# One way to measure how poor or how wrong your model's predictions are is to use a loss function.
#
# Things we need to train:
#
#   LOSS FUNCTION - A function to measure how wrong your model's predictions are to the ideal outputs - lower is better.
#   Note: "loss function", "cost function", and "criterion" are all the same
#
#   OPTIMIZER - Takes into account the loss of a model and adjusts the model's parameters (e.g. weight & bias) to improve the loss function.
#   Note: For PyTorch we need a training loop & testing loop

print("--- L022 ---")
print(list(model_0.parameters()))
