class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> newGrid;
        for(int i = 0; i < m; i++) {
            vector<int> g(n);
            newGrid.push_back(g);
        }

        while(k--) {
            newGrid[0][0] = grid[m - 1][n - 1];
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(j+1<n)
                    newGrid[i][j+1] = grid[i][j];
                    if(i+1<m)
                    newGrid[i + 1][0] = grid[i][n - 1];
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = newGrid[i][j];
                }
            }
        }
        return grid;
    }
};
