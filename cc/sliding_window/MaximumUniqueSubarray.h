// LeetCode: 1695. Maximum Erasure Value (Medium)
class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int n = nums.size();
        int L = 0;
        int R = 0;

        unordered_map<int, int> freq;
        int sum = 0;
        int ans = 0;
        while (R < n) {
            int right = nums[R++];
            sum += right;
            freq[right]++;

            while (freq[right] > 1) {
                int left = nums[L++];
                freq[left]--;
                sum -= left;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};