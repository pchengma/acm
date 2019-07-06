import time


def use_time():
    """print out time in seconds """
    a = 1
    b = 2
    cpu_start = time.clock()
    print(a + b)
    cpu_end = time.clock()
    print('cpu', cpu_end - cpu_start)

