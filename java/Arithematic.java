public class Arithematic {

    public double m_pow(double a, int b) {
        double result = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                result *= a;
            }
            a *= a;
            b >>= 1;
        }
        return result;
    }

}
