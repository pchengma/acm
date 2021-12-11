// LeetCode: 36. Valid Sudoku (Medium)
class Solution {
public:
    bool isValidSudoku(vector <vector<char>> &board) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            set<char> s;
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    if (s.find(board[i][j]) != s.end()) {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            set<char> s;
            for (int i = 0; i < n; ++i) {
                if (board[i][j] != '.') {
                    if (s.find(board[i][j]) != s.end()) {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                set<char> s;
                for (int k = 0; k < 3; ++k) {
                    for (int m = 0; m < 3; ++m) {
                        if (board[i + k][j + m] != '.') {
                            if (s.find(board[i + k][j + m]) != s.end()) {
                                return false;
                            }
                            s.insert(board[i + k][j + m]);
                        }
                    }
                }
            }
        }
        return true;
    }
};