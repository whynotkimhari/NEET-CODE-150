#define pii pair<int,int>
#define qpii queue<pii>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
class Solution {
public:
    int orangesRotting(vvi& grid) {
        int m = grid.size(), n = grid[0].size();
        vvb visited(m, vector<bool>(n, 0));

        qpii qq, subqq;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2 && !visited[i][j]) {
                    subqq.push({i,j});
                }
            }
        }

        int time = -1;

        while(true) {
            while(!subqq.empty()) {
                qq.push(subqq.front());
                subqq.pop();
            }

            while(!qq.empty()) {
                auto f = qq.front();
                int x = f.first, y = f.second;

                if(x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
                    visited[x - 1][y] = true;
                    subqq.push({x - 1, y});
                }

                if(x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                    visited[x + 1][y] = true;
                    subqq.push({x + 1, y});
                }

                if(y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
                    visited[x][y - 1] = true;
                    subqq.push({x, y - 1});
                }

                if(y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                    visited[x][y + 1] = true;
                    subqq.push({x, y + 1});
                }

                qq.pop();
            }

            time++;

            if(subqq.empty() && qq.empty()) break;
        }

        // Last checking if there is any fresh orange
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return time;
    }
};
