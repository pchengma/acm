// LeetCode: 844. Backspace String Compare (Easy)
class Solution {
public:
    string build(string s) {
        stack<char> stk;

        for (char &c: s) {
            if (c == '#') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(c);
            }
        }

        string processed = "";
        while (!stk.empty()) {
            processed += stk.top();
            stk.pop();
        }

        return processed;
    }

    bool backspaceCompare(string s, string t) {
        string sFinal = build(s);
        string tFinal = build(t);
        return sFinal == tFinal;
    }
};