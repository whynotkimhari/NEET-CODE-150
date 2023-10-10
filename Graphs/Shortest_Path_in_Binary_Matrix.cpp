class Solution {
public:
    int bfs(int i, int j, int& n, vector<vector<int>>& grid, vector<vector<int>>& newGrid, vector<vector<bool>>& visited) {
        queue<pair<int, int>> sq, q;
        sq.push({i, j});
        visited[i][j] = true;
        int curr = 0;

        while(!sq.empty() || !q.empty()) {
            while(!sq.empty()) {
                q.push(sq.front());
                sq.pop();
            }
            curr++;

            while(!q.empty()) {
                auto f = q.front();
                int x = f.first, y = f.second;

                newGrid[x][y] = curr;

                for(int rd = -1; rd <= 1; rd++) {
                    for(int cd = -1; cd <= 1; cd++) {
                        if((rd || cd) && x + rd >= 0 && y + cd >= 0 && x + rd < n && y + cd < n && !visited[x + rd][y + cd] && !grid[x + rd][y + cd]) {
                            sq.push({x + rd, y + cd});
                            visited[x + rd][y + cd] = true;
                        }
                    }
                }
                q.pop();
            }
        }

        return curr;        
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> newGrid(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        if(!grid[0][0]) bfs(0, 0, n, grid, newGrid, visited);
        
        return newGrid[n - 1][n - 1];
    }
};
