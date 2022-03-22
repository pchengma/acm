// LeetCode: 1663. Smallest String With A Given Numeric Value (Medium)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');

        k -= n;

        while (k > 0) {
            ans[--n] += min(k, 25);
            k -= min(k, 25);
        }

        return ans;
    }
};