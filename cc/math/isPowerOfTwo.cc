// LeetCode: 231. Power of Two (Easy)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0) {
            return !(n & (n - 1));
        }
        return false;
    }
};