// LeetCode: 59. Spiral Matrix II (Medium)
class Solution {
public:

    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }

    vector <vector<int>> generateMatrix(int n) {
        vector <vector<int>> ans(n, vector<int>(n));

        int cnt = 1;
        int dir[4][2] = {{0,  1},
                         {1,  0},
                         {0,  -1},
                         {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;

        while (cnt <= n * n) {
            ans[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);

            if (ans[r][c] != 0) {
                d = (d + 1) % 4;
            }

            row += dir[d][0];
            col += dir[d][1];
        }
        return ans;
    }
};