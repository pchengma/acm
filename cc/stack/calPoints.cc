// LeetCode: 682. Baseball Game (Easy)
class Solution {
public:
    int calPoints(vector <string> &ops) {
        vector<int> stk;

        for (auto &i: ops) {
            if (i == "+") {
                int top = stk.back();
                stk.pop_back();
                int newtop = top + stk.back();
                stk.push_back(top);
                stk.push_back(newtop);
            } else if (i == "C") {
                stk.pop_back();
            } else if (i == "D") {
                stk.push_back(2 * stk.back());
            } else {
                stk.push_back(stoi(i));
            }
        }

        int ans = 0;
        for (auto &i: stk) {
            ans += i;
        }

        return ans;
    }
};