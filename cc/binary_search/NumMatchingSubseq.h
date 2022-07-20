// LeetCode: 792. Number of Matching Subsequences (Medium)
class NumMatchingSubseq {
public:
    int numMatchingSubseq(string s, vector <string> &words) {
        vector <vector<int>> check(126, vector<int>());

        for (int i = 0; i < s.size(); ++i) {
            check[s[i]].push_back(i);
        }

        for (auto &it: check) {
            sort(it.begin(), it.end());
        }

        int count = 0;
        for (string it: words) {
            int start = INT_MIN;
            bool deter = true;
            if (it.size() > s.size()) {
                continue;
            }

            for (int i = 0; i < it.size(); ++i) {
                if (i > 0 && it[i] == it[i - 1]) {
                    start++;
                }

                if (check[it[i]].empty()) {
                    i = it.size();
                    deter = false;
                } else {
                    if (lower_bound(check[it[i]].begin(), check[it[i]].end(), start) != check[it[i]].end()) {
                        start = *lower_bound(check[it[i]].begin(), check[it[i]].end(), start);
                    } else {
                        i = it.size();
                        deter = false;
                    }
                }
            }

            if (deter) {
                count++;
            }
        }

        return count;
    }
};