# Building my first PyTorch model

import torch
from torch import nn
import matplotlib.pyplot as plt

# Condensed version of 018_training_test_sets.py
# ----------------------------------------------------------------------
weight = 0.7
bias = 0.3
start = 0
end = 1
step = 0.02
X = torch.arange(start, end, step).unsqueeze(dim=1)
y = weight * X + bias   # Y = a + bX
train_split = int(0.8 * len(X))  
X_train = X[:train_split]   # beginning -> train_split
y_train = y[:train_split]
X_test = X[train_split:]    # train_split -> end
y_test = y[train_split:]
print(len(X_train), len(y_train), len(X_test), len(y_test))
def plot_predictions(train_data = X_train,
                     train_labels = y_train,
                     test_data = X_test,
                     test_labels = y_test,
                     predictions = None):
    """
    Plots training data, test data, and compares predictions
    """
    plt.figure(figsize=(10, 7))
    plt.scatter(train_data, train_labels, c='b', s=4, label="Training data")
    plt.scatter(test_data, test_labels, c='g', s=4, label="Testing data")
    if predictions is not None:
        plt.scatter(test_data, predictions, c='r', s=4, label="Predictions")
    plt.legend(prop={"size": 14})
plot_predictions()
# plt.show()    # uncomment if u want to see the graph
# ----------------------------------------------------------------------

# What our model does:
# - Start with random values (weight & bias)
# - Look at training data and adjust the random values to better represent (or get closer to) the ideal values
# Does this through "Gradient Descent" and "Backpropogation"

# Create a linear regression model class
class LinearRegressionModel(nn.Module): # <- almost everything in PyTorch inherits from nn.Module
    def __init__(self):
        super().__init__()
        self.weighs = nn.Parameter(torch.randn(1,
                                               requires_grad=True,
                                               dtype=torch.float32))
        self.bias = nn.Parameter(torch.randn(1,
                                             requires_grad=True,
                                             dtype=torch.float32))
        
    # Forward method to define the computation in the model
    def forward(self, x: torch.Tensor) -> torch.Tensor: # <- "x" is the input data
        return self.weighs * x + self.bias # this is the linear regression data
        
# PyTorch model building essentials
#
# torch.nn - Contains all of the building components for computational graphs (a neural network can be considered as this).
# torch.nn.Parameter - What parameters should our model try and learn, often a PyTorch layer from torch.nn will set these for us.
# torch.nn.Module - The base class for all neural network modules, if you subclass it, you should overwrite forward().
# torch.optim - This is where the optimizers in PyTorch live, they will help with gradient descent.
# def forward() - All nn.Module subclasses require you to overwrite forward(). This method defines what happens in the forward computation.