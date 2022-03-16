// LeetCode: 946. Validate Stack Sequences (Medium)
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;

        int j = 0;

        for (auto &i: pushed) {
            stk.push(i);
            while (!stk.empty() && j < pushed.size() && stk.top() == popped[j]) {
                stk.pop();
                ++j;
            }
        }

        return j == pushed.size();
    }
};