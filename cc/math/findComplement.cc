// LeetCode: 476. Number Complement (Easy)
class Solution {
public:
    int findComplement(int num) {
        return ~(-1u << ((int) log2(num) + 1)) ^ num;
    }
};