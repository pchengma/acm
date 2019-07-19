
def pad_zeros_front(max_length):
    s = "{:0>" + str(max_length) + "d}"
    a = s.format(123)
    print(a)


def pad_zeros_end(max_length):
    s = "{:." + str(max_length) + "f}"
    a = s.format(123)
    print(a)

