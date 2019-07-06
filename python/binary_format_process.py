
def decimal2binary(num, k_prec=3):
    """
    Convert decimal to binary.
    :param num:
    :param k_prec:
    :return: binary string
    """
    binary = ""
    integral = int(num)
    fractional = num - integral
    while integral:
        rem = integral % 2
        binary += str(rem)
        integral = integral / 2
    binary = binary[::-1]
    binary = binary + '.'
    while k_prec:
        fractional = fractional * 2
        frac_bit = int(fractional)
        if frac_bit == 1:
            fractional = fractional - frac_bit
            binary = binary + '1'
        else:
            binary = binary + '0'
        k_prec = k_prec - 1
    return binary

