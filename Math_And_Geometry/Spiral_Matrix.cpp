class Solution {
public:
    void find_bound(vector<int> &answer, int &start_x, int &start_y, int &end_x, int &end_y, vector<vector<int>>& matrix) {
        if(start_x == end_x) {
            for(int i = start_y; i <= end_y; i++) {
                answer.push_back(matrix[i][start_x]);
            }
            start_x++; start_y++;
            end_x--; end_y--;
            return;
        }
        if(start_y == end_y) {
            for(int i = start_x; i <= end_x; i++) {
                answer.push_back(matrix[start_y][i]);
            }
            start_x++; start_y++;
            end_x--; end_y--;
            return;
        }
        for(int i = start_x; i <= end_x; i++) {
            answer.push_back(matrix[start_x][i]);
        }
        for(int i = start_y + 1; i <= end_y;i++) {
            answer.push_back(matrix[i][end_x]);
        }
        for(int i = end_x - 1; i >= start_x; i--) {
            answer.push_back(matrix[end_y][i]);
        }
        for(int i = end_y - 1; i > start_y; i--) {
            answer.push_back(matrix[i][start_y]);
        }
        start_x++; start_y++;
        end_x--; end_y--;
        return;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int start_x = 0, start_y = 0, end_x = matrix[start_x].size() - 1, end_y = matrix.size() - 1;
        while(true) {
            find_bound(answer, start_x, start_y, end_x, end_y, matrix);
            if(start_x > end_x || start_y > end_y) break;
        }
        
        return answer;
    }
};
