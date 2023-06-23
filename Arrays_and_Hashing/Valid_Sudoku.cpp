class Solution {
public:
    bool check3x3(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i+= 3) {
            for(int j = 0; j < 9; j+= 3) {
                vector<int> c(9, 0);
                for(int x = i; x < i + 3; x++) {
                    for(int y = j; y < j + 3; y++) {
                        if(board[x][y] != '.') {
                            c[board[x][y] - '0' - 1]++;
                            if(c[board[x][y] - '0' - 1] >= 2) return false;
                            }
                    }
                }
            }
        }
        return true;
    }

    bool checkRow(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            vector<int> c(9, 0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    c[board[i][j] - '0' - 1]++;
                    if(c[board[i][j] - '0' - 1] >= 2) return false;
                }
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>> &board) {
        for(int j = 0; j < 9; j++) {
            vector<int> c(9, 0);
            for(int i = 0; i < 9; i++) {
                if(board[i][j] != '.') {
                    c[board[i][j] - '0' - 1]++;
                    if(c[board[i][j] - '0' - 1] >= 2) return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkCol(board) && checkRow(board) && check3x3(board);
    }
};
