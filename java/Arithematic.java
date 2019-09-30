public class Arithematic {

    // By bit-wise operation, or say, the Fourier series
    double m_pow(double a, int b) {
        double result = 1;
        if (b == 0) {
            return 1;
        }
        if (a != 1 && a != -1 && b == -2147483648) {
            return 0;
        }
        if (a == -1 && b == -2147483648) {
            return 1;
        }
        if (b < 0 && b > -2147483648) {
            a = 1 / a;
            b = Math.abs(b);
        }
        while (b > 0) {
            if (b % 2 != 0) {
                result *= a;
            }
            a *= a;
            b /= 2;
        }
        return result;
    }

    // Decimal to Binary
    StringBuilder dec2bin(int num) {
        StringBuilder s = new StringBuilder();
        int temp;
        while (num != 0) {
            temp = num % 2;
            num /= 2;
            s.append(temp);
        }
        if (s.length() < 8) {
            s.append(0);
        }
        return s.reverse();
    }
}