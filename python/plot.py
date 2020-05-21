# rs encode
import matplotlib.pyplot as plt


def autolabel(rects):
    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x() + rect.get_width() / 2. - 0.2, 1.03 * height, '%s' % float(height))


name_list = ['128 KB', '8 MB', '16 MB', '32 MB', '64 MB', '128 MB', '256 MB']
num_list = [94459.09, 28194.94, 22071.01, 19436.66, 19438.92, 17890.45, 17864.75]
num_list1 = [60841.00, 27066.92, 19936.11, 22588.32, 23705.32, 16140.48, 15803.37]
x = list(range(len(num_list)))
total_width, n = 0.8, 2
width = total_width / n

a = plt.bar(x, num_list, width=width, label='xor_gen', fc='y')
for i in range(len(x)):
    x[i] = x[i] + width
b = plt.bar(x, num_list1, width=width, label='C bit-wise XOR', tick_label=name_list, fc='r')
autolabel(a)
autolabel(b)

plt.xlabel('file size')
plt.ylabel('throughput (MB/s)')

plt.legend()
plt.show()
