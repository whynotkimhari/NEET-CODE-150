#define vvi vector<vector<int>>
#define vi vector<int>

class NumMatrix {
private:
    vvi Mat, preMat, posMat;
    int len;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->Mat = matrix;

        for(auto &arr: matrix) {
            int len = arr.size();
            this->len = len;
            vi pre(len, 0), pos(len, 0);
            pre[0] = arr[0];
            pos[len - 1] = arr[len - 1];

            for(int i = 1; i < len; i++) {
                pre[i] = pre[i - 1] + arr[i];
            }

            for(int i = len - 2; i >= 0; i--) {
                pos[i] = pos[i + 1] + arr[i];
            }

            this->preMat.push_back(pre);
            this->posMat.push_back(pos);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            int SigmaRow = this->posMat[i][0];
            int a = col1 > 0 ? this->preMat[i][col1 - 1] : 0;
            int b = col2 < this->len - 1 ? this->posMat[i][col2 + 1] : 0;
            sum = sum + (SigmaRow - a - b);
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
