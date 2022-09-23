// LeetCode: 1680. Concatenation of Consecutive Binary Numbers (Medium)
class ConcatenatedBinary {
public:
    int concatenatedBinary(int n) {
        int next = 1, length = 1;
        long max_n = pow(10, 9) + 7, result = 0;
        for (int i = 0; i <= n; i++) {
            if (i == next) {
                next *= 2;
                length++;
            }

            result = (result * next + i) % max_n;
        }
        return result;
    }
};