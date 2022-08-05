// LeetCode: 377. Combination Sum IV (Medium)
class CombinationSum4 {
public:
    vector<int> dp;

    int help(vector<int> &nums, int T, int n) {
        if (T == 0) {
            return 1;
        }

        int ans = 0;

        if (dp[T] != -1) {
            return dp[T];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= T) {
                ans += help(nums, T - nums[i], n);
            }
        }
        return dp[T] = ans;
    }

    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        dp.resize(target + 1, -1);
        return help(nums, target, n);
    }
};