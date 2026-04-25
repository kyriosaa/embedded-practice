# Splitting data into training and test sets (one of the most important concepts in machine learning in general)

# Training set      (Course materials - train the model)
# Validation set    (Practice exam - tune model patterns)
# Test set          (Final exam - see if model is ready for the wild)

# At the end of the day, we want the model to be able to perform well on data that we haven't seen before

import torch
from torch import nn
import matplotlib.pyplot as plt

weight = 0.7
bias = 0.3

start = 0
end = 1
step = 0.02

X = torch.arange(start, end, step).unsqueeze(dim=1)
y = weight * X + bias   # Y = a + bX

# Create a train/test split
train_split = int(0.8 * len(X))     # 40 - so train 40 to predict the other 10 since len(X) is 50 and we're doing 80/20 split

X_train = X[:train_split]   # beginning -> train_split
y_train = y[:train_split]

X_test = X[train_split:]    # train_split -> end
y_test = y[train_split:]

print(len(X_train), len(y_train), len(X_test), len(y_test))
# but... how can we better visualize this data?

def plot_predictions(train_data = X_train,
                     train_labels = y_train,
                     test_data = X_test,
                     test_labels = y_test,
                     predictions = None):
    """
    Plots training data, test data, and compares predictions
    """
    plt.figure(figsize=(10, 7))

    # Plot training data in blue
    plt.scatter(train_data, train_labels, c='b', s=4, label="Training data")

    # Plot test data in green
    plt.scatter(test_data, test_labels, c='g', s=4, label="Testing data")

    # Are there predictions?
    if predictions is not None:
        # Plot predictions if exists
        plt.scatter(test_data, predictions, c='r', s=4, label="Predictions")

    # Show legend
    plt.legend(prop={"size": 14})

plot_predictions()
plt.show()