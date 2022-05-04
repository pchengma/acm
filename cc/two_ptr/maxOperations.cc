// LeetCode: 1679. Max Number of K-Sum Pairs (Medium)
class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int s = 0, e = nums.size() - 1, cnt = 0;
        while (s < e) {
            if (nums[s] + nums[e] == k) {
                cnt++;
                s++;
                e--;
            } else if (nums[s] + nums[e] > k) {
                e--;
            } else {
                s++;
            }
        }

        return cnt;
    }
};