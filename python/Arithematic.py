import math


def triangle_function(theta, label=0):
    if label == 0:
        return math.sin(theta)
    elif label == 1:
        return math.cos(theta)
    else:
        return 0

