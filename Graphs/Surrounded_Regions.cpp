#define qpii queue<pair<int,int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>

class Solution {
public:
    void bfs(int i, int j, qpii& q, vvb& visited, vvc& grid, int &m, int &n, vvb& flippable) {
        visited[i][j] = true;
        q.push({i, j});

        while(!q.empty()) {
            auto f = q.front();
            int x = f.first, y = f.second;

            if(x - 1 >= 0 && grid[x - 1][y] == 'O' && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
                flippable[x - 1][y] = 0;
            }
            if(x + 1 < m && grid[x + 1][y] == 'O' && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
                flippable[x + 1][y] = 0;

            }
            if(y - 1 >= 0 && grid[x][y - 1] == 'O' && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
                flippable[x][y - 1] = 0;

            }
            if(y + 1 < n && grid[x][y + 1] == 'O' && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
                flippable[x][y + 1] = 0;

            }

            q.pop();
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vvb visited(m, vector<bool>(n, 0));
        vvb flippable(m, vector<bool>(n, 1));

        qpii q;

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O' && !visited[0][i]) {
                flippable[0][i] = 0;
                bfs(0, i, q, visited, board, m, n, flippable);
            }
            if(board[m - 1][i] == 'O' && !visited[m - 1][i]) {
                flippable[m - 1][i] = 0;
                bfs(m - 1, i, q, visited, board, m, n, flippable);
            }
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                flippable[i][0] = 0;
                bfs(i, 0, q, visited, board, m, n, flippable);
            }
            if(board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                flippable[i][n - 1] = 0;
                bfs(i, n - 1, q, visited, board, m, n, flippable);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(flippable[i][j]) board[i][j] = 'X';
            }
        }
    }
};
