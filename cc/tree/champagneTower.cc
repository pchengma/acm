// LeetCode: 799. Champagne Tower (Medium)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector <vector<double>> cup(101, vector<double>(101, 0.0));

        cup[0][0] = poured;

        for (int r = 0; r < 100; ++r) {
            for (int c = 0; c <= r; ++c) {
                if (cup[r][c] >= 1) {
                    double spilt_out = cup[r][c] - 1;

                    cup[r + 1][c] += spilt_out / 2.0;
                    cup[r + 1][c + 1] += spilt_out / 2.0;

                    cup[r][c] = 1;
                }
            }
        }

        return cup[query_row][query_glass];
    }
};