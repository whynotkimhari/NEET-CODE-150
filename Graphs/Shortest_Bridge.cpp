class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& ans, int m, int n) {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        ans.push_back({i, j});

        q.push({i, j});
        while(!q.empty()) {
            auto f = q.front();
            int x = f.first, y = f.second;

            if(x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == 1) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
                ans.push_back({x - 1, y});
            }

            if(x + 1 < m && !visited[x + 1][y] && grid[x + 1][y] == 1) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
                ans.push_back({x + 1, y});
            }

            if(y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == 1) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
                ans.push_back({x, y - 1});
            }

            if(y + 1 < n && !visited[x][y + 1] && grid[x][y + 1] == 1) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
                ans.push_back({x, y + 1});
            }

            q.pop();
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> i1, i2;

        bool first = true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    if(first) {
                        bfs(i, j, grid, visited, i1, m, n);
                        first = false;
                    }
                    else bfs(i, j, grid, visited, i2, m, n);
                }
            }
        }

        int min = INT_MAX;
        int d;

        for(int i = 0; i < i1.size(); i++) {
            for(int j = 0; j < i2.size(); j++) {
                d = abs(i1[i].first - i2[j].first) + abs(i1[i].second - i2[j].second);
                min = min < d ? min : d;
            }
        }

        return min - 1;
    }
};
