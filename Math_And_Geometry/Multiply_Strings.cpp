class Solution {
public:
    string addRv(string num1, string num2) {
        int r = 0, i = 0, j = 0;
        string s = "";
        while(i < num2.size() && j < num1.size()) {
            int v = (int(num1[j] - '0') + int(num2[i] - '0') + r) % 10;
            r = (int(num1[j] - '0') + int(num2[i] - '0') + r) / 10;
            s = s + to_string(v);
            i++;j++;
        }
        while(i < num2.size()) {
            int v = (int(num2[i] - '0') + r) % 10;
            r = (int(num2[i] - '0') + r) / 10;
            s = s + to_string(v);
            i++;
        }
        while(j < num1.size()) {
            int v = (int(num1[j] - '0') + r) % 10;
            r = (int(num1[j] - '0') + r) / 10;
            s = s + to_string(v);
            j++;
        }
        if(r) {
            s = s + to_string(r);
            r = 0;
        }

        return s;
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string s = "";
        for(int i = 0; i < num2.size(); i++) {
            int r = 0;
            int cnt = i;
            string pre_s = "";
            while(cnt) {
                pre_s += '0';
                cnt--;
            }
            for(int j = 0; j < num1.size(); j++) {
                int v = (int(num1[j] - '0') * int(num2[i] - '0') + r) % 10;
                r = (int(num1[j] - '0') * int(num2[i] - '0') + r) / 10;
                pre_s = pre_s + to_string(v);
            }
            if(r) {
                pre_s = pre_s + to_string(r);
            }
            if(!s.size()) s = pre_s;
            else s = addRv(s, pre_s);
            
        }
        reverse(s.begin(), s.end());
        while(s.size() > 1 && s[0] == '0') {
            s = s.substr(1, s.size());
        }
        return s;
    }
};
