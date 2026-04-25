from L020_model_internals import *
import torch

# Making predictions using `torch.inference_mode()`
#
# To check our model's predictive power, let's see how well it predicts `y_test` based on `x_test`.
# When we pass data through our model, it's going to run it through the forward() method.

with torch.inference_mode():
    y_preds = model_0(X_test)   # passing `X_test`` through our model_0 and it should successfully predict `y_test`

print(f"y_preds predictions:\n {y_preds}\n")