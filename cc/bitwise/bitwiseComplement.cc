// LeetCode: 1009. Complement of Base 10 Integer (Easy)
// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        int res = 0, mask = 1, tmp = n;

        if (n == 0) {
            return 1;
        }

        while (tmp) {
            res += mask ^ (n & mask);
            mask <<= 1;
            tmp >>= 1;
        }

        return res;
    }
};