class Solution {
public:
    string addBinary(string a, string b) {
        int tmp = 0;
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 && j >= 0) {
            if(tmp == 0) {
                if(a[i] == '1') {
                    if(b[j] == '1') {
                        tmp++;
                        ans = "0" + ans;
                    }
                    else ans = "1" + ans;
                }
                else {
                    if(b[j] == '1') ans = "1" + ans;
                    else ans = "0" + ans;
                }
            }
            else {
                if(a[i] == '1') {
                    if(b[j] == '1') ans = "1" + ans;
                    else ans = "0" + ans;
                }
                else {
                    if(b[j] == '1') ans = "0" + ans;
                    else {
                        ans = "1" + ans;
                        tmp--;
                    }
                }
            }
            i--;j--;
        }
        while(i >= 0) {
            if(tmp == 0) {
                ans = a[i] + ans;
            }
            else {
                if(a[i] == '1') {
                    ans = '0' + ans;
                }
                else {
                    ans = '1' + ans;
                    tmp--;
                }
            }
            i--;
        }
        while(j >= 0) {
            if(tmp == 0) {
                ans = b[j] + ans;
            }
            else {
                if(b[j] == '1') {
                    ans = '0' + ans;
                }
                else {
                    ans = '1' + ans;
                    tmp--;
                }
            }
            j--;
        }

        if(tmp) {
            ans = '1' + ans;
        }

        return ans;
    }
};
