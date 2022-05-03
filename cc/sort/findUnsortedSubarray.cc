// LeetCode: 581. Shortest Unsorted Continuous Subarray (Medium)
class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> snums(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            snums[i] = nums[i];
        }

        sort(snums.begin(), snums.end());

        int start = nums.size(), end = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (snums[i] != nums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }

        return (end - start >= 0 ? end - start + 1 : 0);
    }
};