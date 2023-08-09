class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0, cnt = 1;
        int max1 = n - 1, max2 = n - 1;
        int min1 = 0, min2 = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        bool case1 = true, case2 = false, case3 = false, case4 = false;
        auto c = n * n;
        while(c--) {
            matrix[i][j] = cnt++;
            
            if(case1) {
                j++;

                if(j > max1) {
                    i++;
                    j--;
                    case1 = false;
                    case2 = true;
                    max1--;
                }
            }

            else if(case2) {
                i++;

                if(i > max2) {
                    i--; j--;
                    case3 = true;
                    case2 = false;
                    max2--;
                }
            }

            else if(case3) {
                j--;

                if(j < min1) {
                    i--; j++;
                    case4 = true;
                    case3 = false;
                    min1++;
                }
            }

            else {
                i--;

                if(i < min2) {
                    i++; j++;
                    case1 = true;
                    case4 = false;
                    min2++;
                }
            }
            
        }

        return matrix;
    }
};
