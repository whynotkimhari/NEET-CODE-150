class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> Xaxis, Yaxis;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(!matrix[i][j]) {
                    Xaxis.push_back(i);
                    Yaxis.push_back(j);
                }
            }
        }

        for(auto &x: Xaxis) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[x][i] = 0;
            }
        }

        for(auto &y: Yaxis) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][y] = 0;
            }
        }
    }
};
