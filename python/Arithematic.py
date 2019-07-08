import math
import numpy as np


def eigen_lin(mat, label=0):
    if label == 0:
        vals, cols = np.linalg.eig(mat)
        return [vals, cols]
    else:
        return 0


def triangle_function(theta, label=0):
    if label == 0:
        return math.sin(theta)
    elif label == 1:
        return math.cos(theta)
    else:
        return 0

