#define qpii queue<pair<int,int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
class Solution {
public:
    void bfs(int i, int j, qpii& q, vvb& visited, vvc& grid, int &m, int &n) {
        visited[i][j] = true;
        q.push({i, j});

        while(!q.empty()) {
            auto f = q.front();
            int x = f.first, y = f.second;

            if(x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if(x + 1 < m && grid[x + 1][y] == '1' && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if(y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
            if(y + 1 < n && grid[x][y + 1] == '1' && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }

            q.pop();
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vvb visited(m, vector<bool>(n, 0));

        qpii q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, q, visited, grid, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};
