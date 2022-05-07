// LeetCode: 456. 132 Pattern (Medium)
class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> st;

        int third_element = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third_element) {
                return true;
            }

            while (!st.empty() && st.top() < nums[i]) {
                third_element = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};