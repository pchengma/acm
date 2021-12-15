// LeetCode: 20. Valid Parentheses (Easy)
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                parentheses.push(s[i]);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                switch (s[i]) {
                    case ')':
                        if (parentheses.top() != '(') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                    case '}':
                        if (parentheses.top() != '{') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                    case ']':
                        if (parentheses.top() != '[') {
                            return false;
                        } else {
                            parentheses.pop();
                        }
                        break;
                    default:
                        return false;
                        break;
                }
            }
        }

        return parentheses.empty();
    }
};