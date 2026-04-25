# Data (preparing and loading)

# Data can be almost anything in machine learning
# - Excel spreadsheet
# - Images of any kind
# - Videos (YouTube has lots of data...)
# - Audio (Songs and Podcasts)
# - DNA
# - Text

# Machine learning is a game of two parts
# 1. Get data into a numerical representation
# 2. Build a model to learn patterns in that numerical representation

# To showcase this, let's create some *known* data using the linear regression formula
# We'll use a linear regression formula to make a straight line with *known* **parameters**
# Y = a + bX

import torch

# Create *known* parameters
weight = 0.7
bias = 0.3

# Create data
start = 0
end = 1
step = 0.02
X = torch.arange(start, end, step).unsqueeze(dim=1)
y = weight * X + bias   # Y = a + bX

print(X[:10])   # beginning to 10th index
print(y[:10])

print(len(X)) 
print(len(y))