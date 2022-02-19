// LeetCode: 20. Valid Parentheses (Easy)
class Solution {
public:
    /**
     * @param s: a string of parentheses
     * @return true if the parentheses are all pairs in order; false otherwise
     */
    bool isValid(string s) {
        // Init a stack for checking:
        stack<char> parentheses;

        // Check:
        for (int i = 0; i < s.length(); ++i) {
            // s[i] is a left parentheses, push s[i] into stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                parentheses.push(s[i]);
            }
                // s[i] is a right parentheses, check
            else {
                // stack is empty, so there is no match for s[i], return false
                if (parentheses.empty()) {
                    return false;
                }

                // element at stack top is the match of s[i], pop the element
                if ((s[i] == ')' && parentheses.top() == '(') ||
                    (s[i] == ']' && parentheses.top() == '[') ||
                    (s[i] == '}' && parentheses.top() == '{')) {
                    parentheses.pop();
                } else {  // element at stack top does not match s[i], return false
                    return false;
                }
            }
        }

        // no remaining left parentheses, return true; otherwise, return false
        return parentheses.empty();
    }
};