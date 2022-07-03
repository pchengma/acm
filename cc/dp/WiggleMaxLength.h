// LeetCode: 376. Wiggle Subsequence (Medium)
class WiggleMaxLength {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size(), up = 1, down = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            }
            if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return min(n, max(up, down));
    }
};