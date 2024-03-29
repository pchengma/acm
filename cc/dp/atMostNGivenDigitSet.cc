// LeetCode: 902. Numbers At Most N Given Digit Set (Hard)
class Solution {
public:
    int atMostNGivenDigitSet(vector <string> &digits, int n) {
        string upperLimit = to_string(n);
        int digit = upperLimit.size(), digitsize = digits.size(), result = 0;

        for (int i = 1; i < digit; ++i) {
            result += pow(digitsize, i);
        }

        for (int i = 0; i < digit; ++i) {
            bool startingSameNum = false;
            for (string &d: digits) {
                if (d[0] < upperLimit[i]) {
                    result += pow(digitsize, digit - i - 1);
                } else if (d[0] == upperLimit[i]) {
                    startingSameNum = true;
                }
            }
            if (!startingSameNum) {
                return result;
            }
        }

        return result + 1;
    }
};