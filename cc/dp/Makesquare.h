// LeetCode: 473. Matchsticks to Square (Meidum)
class Makesquare {
public:
    int getsum;
    vector<int> t;

    bool makesquare(vector<int> &matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        getsum = sum / 4;
        t.resize(1 << (matchsticks.size() + 1), -1);
        return solve(matchsticks, 4, 0, 0, 0);
    }

    bool solve(vector<int> &a, int k, int cursum, int mask, int i) {
        if (k == 1) {
            return true;
        }

        if (i >= a.size()) {
            return false;
        }

        if (t[mask] != -1) {
            return t[mask];
        }

        if (cursum == getsum) {
            return t[mask] = solve(a, k - 1, 0, mask, 0);
        }

        for (int j = i; j < a.size(); j++) {
            if (!(mask & (1 << j)) && a[j] + cursum <= getsum && solve(a, k, a[j] + cursum, mask | (1 << j), j + 1)) {
                return t[mask] = true;
            }
        }
        return t[mask] = false;
    }
};