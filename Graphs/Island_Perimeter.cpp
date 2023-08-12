class Solution {
public:
    bool isTopFree(vector<vector<int>> &grid, int i, int j) {
        if(i == 0 || !grid[i-1][j]) return true;
        return false;
    }
    bool isBotFree(vector<vector<int>> &grid, int i, int j) {
        if(i == grid.size()-1 || !grid[i+1][j]) return true;
        return false;
    }
    bool isRightFree(vector<vector<int>> &grid, int i, int j) {
        if(j == grid[i].size()-1 || !grid[i][j+1]) return true;
        return false;
    }
    bool isLeftFree(vector<vector<int>> &grid, int i, int j) {
        if(j == 0 || !grid[i][j-1]) return true;
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]) {
                    perimeter += isTopFree(grid,i,j) + isBotFree(grid,i,j) + isLeftFree(grid,i,j) + isRightFree(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};
