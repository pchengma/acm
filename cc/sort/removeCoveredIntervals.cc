// LeetCode: 1288. Remove Covered Intervals (Medium)
class Solution {
public:
    int removeCoveredIntervals(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0];
        int right = intervals[0][1];

        int res = 1;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > left && intervals[i][1] > right) {
                ++res;
            }

            if (intervals[i][1] > right) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        return res;
    }
};