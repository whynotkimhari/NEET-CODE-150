class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows, vector<char>(s.size(), ' '));
        string ans = "";

        int i = 0, j = 0, k = 0;
        while(k < s.size()) {
            v[i][j] = s[k];
            k++; i++;
            if(i == numRows) {
                i--;
                for(int z = 0; z < numRows - 2; z++) {
                    i--; j++;
                    if(isalpha(s[k]) || s[k] == ',' || s[k] == '.') {
                        v[i][j] = s[k];
                        k++;
                    }
                    
                }
                j++;
                i = 0;
            }
        }

        for(int a = 0; a < numRows; a++) {
            for(int b = 0; b < v[0].size(); b++) {
                if(v[a][b] != ' ') {
                    ans += v[a][b];
                }
            }
        }

        return ans;
    }
};
