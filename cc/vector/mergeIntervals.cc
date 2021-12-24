// LeetCode: 56. Merge Intervals (Medium)
class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        vector <vector<int>> result;

        if (intervals.size() == 0) {
            return result;
        }

        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        int j = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (result[j][1] >= intervals[i][0]) {
                result[j][1] = max(result[j][1], intervals[i][1]);
            } else {
                ++j;
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};