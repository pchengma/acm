from PIL import Image
import numpy as np
import matplotlib.pyplot as plt


img_path = 'fig/test1.jpg'
img1 = Image.open(img_path)
img1 = np.array(img1)
plt.imshow(img1)
plt.show()
