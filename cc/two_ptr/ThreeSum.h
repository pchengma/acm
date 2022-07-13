// LeetCode: 15. 3Sum (Medium)
class ThreeSum {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int tar = -1 * nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (m.count(tar - nums[j]) > 0 && m[tar - nums[j]] > j) {
                    vector<int> cur;
                    cur.push_back(-1 * tar);
                    cur.push_back(nums[j]);
                    cur.push_back(tar - nums[j]);

                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
};