// LeetCode: 1249. Minimum Remove to Make Valid Parentheses (Medium)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack for index of s
        stack<int> idx_stack;

        for (int i = 0; i < s.size(); ++i) {
            // Record index of (:
            if (s[i] == '(') {
                idx_stack.push(i);
            }

            if (s[i] == ')') {
                if (!idx_stack.empty()) {
                    // If stack has (, pop one ( to pair with ):
                    idx_stack.pop();
                } else {
                    // If stack has no (, set ) as #:
                    s[i] = '#';
                }
            }
        }

        // If ( are not all paired, set ( as #, pop until stack is empty:
        while (!idx_stack.empty()) {
            s[idx_stack.top()] = '#';
            idx_stack.pop();
        }

        // Erase all #:
        s.erase(remove(s.begin(), s.end(), '#'), s.end());

        return s;
    }
};