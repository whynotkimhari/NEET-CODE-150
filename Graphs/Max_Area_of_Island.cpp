#define qpii queue<pair<int,int>>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>

class Solution {
public:
    int bfs(int i, int j, qpii& q, vvb& visited, vvi& grid, int &m, int &n) {
        int area = 1;
        visited[i][j] = true;
        q.push({i, j});

        while(!q.empty()) {
            auto f = q.front();
            int x = f.first, y = f.second;

            if(x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
                area++;
            }
            if(x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
                area++;

            }
            if(y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
                area++;

            }
            if(y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
                area++;

            }

            q.pop();
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max = 0;

        vvb visited(m, vector<bool>(n, 0));

        qpii q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    cout << i << " " << j << " ";
                    int v = bfs(i, j, q, visited, grid, m, n);
                    max = max > v ? max : v;
                    cout << max << endl;
                }
            }
        }

        return max;
    }
};
