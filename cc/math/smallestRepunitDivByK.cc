// LeetCode: 1015. Smallest Integer Divisible by K (Medium)
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int hit[100000] = {0}, n = 0, len = 0;
        while (true) {
            ++len;
            n = (n * 10 + 1) % k;

            if (n == 0) {
                return len;
            }

            if (hit[n]) {
                return -1;
            }

            hit[n] = 1;
        }
    }
};