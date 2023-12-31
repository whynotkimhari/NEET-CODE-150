// Sol 1: BFS each cell -> O(n^2 * m^2) : TLE
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();

        vector<vector<int>> answer;
        vector<vector<bool>> possible(r, vector<bool>(c, false));
        possible[0][c - 1] = true;
        possible[r - 1][0] = true;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                bool pacific = false, atlantic = false;
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                
                if(
                    possible[i][j] || 
                    (i - 1 >= 0 && possible[i - 1][j] && heights[i][j] >= heights[i - 1][j]) ||
                    (j - 1 >= 0 && possible[i][j - 1] && heights[i][j] >= heights[i][j - 1]) ||
                    (i + 1 < r && possible[i + 1][j] && heights[i][j] >= heights[i + 1][j]) ||
                    (j + 1 < c && possible[i][j + 1] && heights[i][j] >= heights[i][j + 1])
                ) {
                    vector<int> tmp = {i, j};
                    answer.push_back(tmp);
                    possible[i][j] = true;
                    continue;
                }

                queue<pair<int,int>> q;
                q.push({i, j});

                while(!q.empty()) {
                    auto f = q.front();
                    int x = f.first, y = f.second;
                    visited[x][y] = true;

                    if(x == 0 || y == 0) pacific = true;
                    if(x == r - 1 || y == c - 1) atlantic = true;
                    if(x - 1 >= 0 && heights[x - 1][y] <= heights[x][y] && !visited[x - 1][y]) {
                        q.push({x - 1, y});
                    }
                    if(x + 1 < r && heights[x + 1][y] <= heights[x][y] && !visited[x + 1][y]) {
                        q.push({x + 1, y});
                    }
                    if(y - 1 >= 0 && heights[x][y - 1] <= heights[x][y] && !visited[x][y - 1]) {
                        q.push({x, y - 1});
                    }
                    if(y + 1 < c && heights[x][y + 1] <= heights[x][y] && !visited[x][y + 1]) {
                        q.push({x, y + 1});
                    }

                    q.pop();
                    if(pacific && atlantic) break;
                }

                if(pacific && atlantic) {
                    vector<int> tmp = {i, j};
                    answer.push_back(tmp);
                    possible[i][j] = true;
                }
                
            }
        }

        return answer;

    }
};


// Sol 2: Better way to solve
// Find all cell that can reach Pacific
// Find all cell that can reach Atlantic
// Then merge them to find which cell can reach Pacific and Atlantic
class Solution {
public:
    void dfs(int i, int j, int r, int c, set<pair<int,int>>& visited, vector<vector<int>>& heights, int prev) {
        if(
            visited.find({i, j}) != visited.end() ||
            i < 0 || j < 0 || i == r || j == c ||
            heights[i][j] < prev
        ) return;

        visited.insert({i, j});
        dfs(i - 1, j, r, c, visited, heights, heights[i][j]);
        dfs(i + 1, j, r, c, visited, heights, heights[i][j]);
        dfs(i, j - 1, r, c, visited, heights, heights[i][j]);
        dfs(i, j + 1, r, c, visited, heights, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();

        vector<vector<int>> answer;
        
        set<pair<int,int>> pacific, atlantic;

        for(int i = 0; i < c; i++) {
            dfs(0, i, r, c, pacific, heights, heights[0][i]);
            dfs(r - 1, i, r, c, atlantic, heights, heights[r - 1][i]);
        }

        for(int i = 0; i < r; i++) {
            dfs(i, 0, r, c, pacific, heights, heights[i][0]);
            dfs(i, c - 1, r, c, atlantic, heights, heights[i][c - 1]);
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(
                    pacific.find({i, j}) != pacific.end() && 
                    atlantic.find({i, j}) != atlantic.end()
                ) {
                    vector<int> tmp = {i, j};
                    answer.push_back(tmp);
                }
            }
        }
        
        return answer;

    }
};
