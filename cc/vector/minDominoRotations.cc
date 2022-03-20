// LeetCode: 1007. Minimum Domino Rotations For Equal Row (Medium)
class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        vector<int> dominoes{tops[0], bottoms[0]};

        for (int i = 0; i < 2; ++i) {
            int d = dominoes[i];
            int cnt_top = 0;
            int cnt_bottom = 0;

            for (int j = 0; j < tops.size(); ++j) {
                if (tops[j] != d && bottoms[j] != d) {
                    break;
                }

                if (tops[j] != d) {
                    ++cnt_top;
                }

                if (bottoms[j] != d) {
                    ++cnt_bottom;
                }

                if (j == tops.size() - 1) {
                    return min(cnt_top, cnt_bottom);
                }
            }
        }

        return -1;
    }
};