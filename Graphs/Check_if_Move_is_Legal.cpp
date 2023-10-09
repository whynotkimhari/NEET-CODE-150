class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // There will be 8 ways to check
        // If one of them is true => then return true, else return false
        // How is a way true ?
        // IF we go to that direction and from the start position
        // All next cells are opposite color (not null)
        // To when we met a cell are in the same color
        // Do not forget the path must has length >= 3
        int r = board.size(), c = board[0].size();

        board[rMove][cMove] = color;

        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                if(!dx && !dy) continue;

                int tmprMove = rMove, tmpcMove = cMove, len_path = 1;
                bool find_end_point = false;

                tmprMove += dx, tmpcMove += dy;
                while(tmprMove >= 0 && tmprMove < r && tmpcMove >= 0 && tmpcMove < c) {
                    if(board[tmprMove][tmpcMove] != '.') {
                        len_path++;
                        if(board[tmprMove][tmpcMove] == color) {
                            find_end_point = true;
                            break;
                        }
                    }
                    else break;
                    tmprMove += dx, tmpcMove += dy;
                }

                if(len_path >= 3 && find_end_point) return true;
            }
        }

        return false;
    }
};
