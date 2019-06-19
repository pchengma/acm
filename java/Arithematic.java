public class Arithematic {

    // By bit-wise operation, or say, the Fourier series
    double m_pow(double a, int b) {
        double result = 1;
        if (b == 0) {
            return 1;
        }
        if (b < 0) {
            a = 1/a;
            b = -b;
        }
        while (b > 0) {
            if (b % 2 != 0) {
                result *= a;
            }
            a *= a;
            b >>= 1;
        }
        return result;
    }

}
