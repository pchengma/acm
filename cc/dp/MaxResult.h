// LeetCode: 1696. Jump Game VI (Medium)
class MaxResult {
public:
    int maxResult(vector<int> &nums, int k) {
        priority_queue <pair<int, int>> q;
        int n = nums.size();
        vector<int> dp(n, 0);
        int i;

        for (i = 0; i < n; i++) {
            if (q.empty()) {
                dp[i] = nums[i];
            } else {
                while (!q.empty() && q.top().second < i - k) {
                    q.pop();
                }
                dp[i] = nums[i] + q.top().first;
            }
            q.push({dp[i], i});
        }

        return dp[n - 1];
    }
};