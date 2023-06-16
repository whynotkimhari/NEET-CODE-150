class Solution {
public:
    void fourSwap(int &a, int &b, int &c, int &d) {
        int tmp = d;
        d = c;
        c = b;
        b = a;
        a = tmp;
        return;
    }

    void swapBoundary(int &counter, vector<vector<int>>& matrix) {
    for (int i = counter; i < matrix.size() - counter - 1; i++) {
        fourSwap(matrix[counter][i], matrix[i][matrix.size() - 1 - counter], matrix[matrix.size() - 1 - counter][matrix.size() - 1 - i], matrix[matrix.size() - 1 - i][counter]);
    }
    counter++;
}

    void rotate(vector<vector<int>>& matrix) {
        int counter = 0;
        while(counter < matrix.size()) {
            swapBoundary(counter, matrix);
        }
        return;
    }
};
