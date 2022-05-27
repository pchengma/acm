// LeetCode: 1342. Number of Steps to Reduce a Number to Zero (Easy)
class NumberOfSteps {
public:
    int numberOfSteps(int num) {
        int ans = 0;

        while (num != 0) {
            if (num % 2 == 0) {
                num /= 2;
                ans++;
            } else {
                num--;
                ans++;
            }
        }

        return ans;
    }
};