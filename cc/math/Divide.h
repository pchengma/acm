// LeetCode: 29. Divide Two Integers (Medium)
class Divide {
public:
    int divide(int x, int y) {
        if (x == INT_MIN && y == -1)
            return INT_MAX;

        int sign = ((x > 0 && y > 0) || (x < 0 && y < 0)) ? 1 : -1;
        long a = labs(x), b = labs(y);

        long ans = 0;
        while (a >= b) {
            long temp = b, step = 1;
            while (a >= temp << 1) {
                temp <<= 1;
                step <<= 1;
            }
            a -= temp;
            ans += step;
        }
        return int(sign * ans);
    }
};