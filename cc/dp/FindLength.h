// LeetCode: 718. Maximum Length of Repeated Subarray (Medium)
class FindLength {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector<int> dp(nums2.size() + 1, 0);
        int maxLen = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = nums2.size(); j >= 1; j--) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dp[j - 1];
                    maxLen = max(maxLen, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return maxLen;
    }
};