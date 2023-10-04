#define pii pair<int,int>
#define qpii queue<pair<int,int>>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>

class Solution {
public:
    bool bfs(int i, int j, qpii& q, vvb& visited, vvi& grid, int &m, int &n, vvi& map) {
        bool flag = true;
        visited[i][j] = true;
        q.push({i, j});

        while(!q.empty()) {
            auto f = q.front();
            int x = f.first, y = f.second;

            flag = flag & (grid[x][y] == map[x][y]);

            if(x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if(x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if(y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
            if(y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }

            q.pop();
        }

        return flag;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;

        vvb visited(m, vector<bool>(n, 0));
        qpii q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && !visited[i][j]) {
                    if(bfs(i, j, q, visited, grid2, m, n, grid1)) ans++;
                }
            }
        }

        return ans;
    }
};
