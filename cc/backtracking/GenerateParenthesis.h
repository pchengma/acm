// LeetCode: 22. Generate Parentheses (Medium)
class GenerateParenthesis {
public:
    void helper(int n, int open, int close, string s, vector <string> &result) {
        if (open == n && close == open) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            helper(n, open + 1, close, s + '(', result);
        }

        if (close < open) {
            helper(n, open, close + 1, s + ')', result);
        }
    }

    vector <string> generateParenthesis(int n) {
        vector <string> result;
        helper(n, 0, 0, "", result);

        return result;
    }
};