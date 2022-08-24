// LeetCode: 326. Power of Three (Easy)
class IsPowerOfThree {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) {
            return true;
        }

        if (n <= 0 || n % 3 != 0) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return isPowerOfThree(n);
    }
};