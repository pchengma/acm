// LeetCode: 838. Push Dominoes (Medium)
class PushDominoes {
public:
    string pushDominoes(string dominoes) {
        string ans = dominoes;
        bool to_change = true;
        while (to_change) {
            to_change = false;
            for (int i = 0; i < ans.length(); i++) {
                if (ans[i] == '.') {
                    bool right = false, left = false;
                    if (i < ans.length() && dominoes[i + 1] == 'L') {
                        left = true;
                    }
                    if (i > 0 && dominoes[i - 1] == 'R') {
                        right = true;
                    }
                    if (left && right) {
                        continue;
                    }
                    if (left) {
                        to_change = true;
                        ans[i] = 'L';
                    }
                    if (right) {
                        to_change = true;
                        ans[i] = 'R';
                    }
                }
            }
            dominoes = ans;
        }
        return ans;
    }
};