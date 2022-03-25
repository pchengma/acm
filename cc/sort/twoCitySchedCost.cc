// LeetCode: 1029. Two City Scheduling (Medium)
class Solution {
public:
    int twoCitySchedCost(vector <vector<int>> &costs) {
        vector<int> delta;
        int ans = 0;

        for (int i = 0; i < costs.size(); ++i) {
            ans += costs[i][0];
            delta.push_back(costs[i][1] - costs[i][0]);
        }

        sort(delta.begin(), delta.end());

        for (int i = 0; i < costs.size() / 2; ++i) {
            ans += delta[i];
        }

        return ans;
    }
};