class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";

        string st = "";
        st += num[0];

        for(int i = 1; i< num.size();) {
            if(k) {
                if(st == "") {
                    st += num[i];
                    i++;
                }
                else if(st.back() > num[i]) {
                    while(k && st != "" && st.back() > num[i]) {
                        st.pop_back();
                        k--;
                    }
                }
                else {
                    st += num[i];
                    i++;
                }
                
            }
            else {
                st += num[i];
                i++;
            }
        }

        while(k) {
            st.pop_back();
            k--;
        }

        int id = 0;
        int len = st.size();

        for(int i = 0; i < len; i++) {
            if(st[i] == '0') id++;
            else break;
        }
        
        string res = st.substr(id, len);
        st = res != "" ? res : "0";
        return st;
    }
};