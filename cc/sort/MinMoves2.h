// LeetCode: 462. Minimum Moves to Equal Array Elements II (Medium)
class MinMoves2 {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size(), steps = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n / 2; ++i) {
            steps += nums[n - 1 - i] - nums[i];
        }

        return steps;
    }
};