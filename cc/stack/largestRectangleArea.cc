// LeetCode: 84. Largest Rectangle in Histogram (Hard)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = INT_MIN, area_with_top = 0, top = 0, i = 0, n = heights.size();
        stack<int> s;

        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) s.push(i++);
            else {
                top = s.top();
                s.pop();
                area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
                ans = max(ans, area_with_top);
            }
        }

        while (!s.empty()) {
            top = s.top();
            s.pop();
            area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, area_with_top);
        }
        return ans;
    }
};