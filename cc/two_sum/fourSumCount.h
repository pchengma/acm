// LeetCode: 454. 4Sum II (Medium)
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        map<int, int> mp;
        for (int x: nums1) {
            for (int y: nums2) {
                ++mp[x + y];
            }
        }

        int ans = 0;
        for (int x: nums3) {
            for (int y: nums4) {
                ans += mp[-x - y];
            }
        }

        return ans;
    }
};