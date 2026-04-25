from L019_build_model import *
import torch

# Checking the contents of our PyTorch model

# Now that we've created a model, let's see what's inside...
# We can check using .parameters()

# Create random seed
torch.manual_seed(42) 

# Create an instance of the model (this is a subclass of nn.Module)
model_0 = LinearRegressionModel()

# Check out parameters
print(f"Check parameters:\n {list(model_0.parameters())}\n")

# List named parameters
print(f"List named parameters:\n {model_0.state_dict()}\n")