// LeetCode: 905. Sort Array By Parity (Easy)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        vector<int> ans(nums.size(), 0);
        int t = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                ans[t++] = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                ans[t++] = nums[i];
            }
        }

        return ans;
    }
};