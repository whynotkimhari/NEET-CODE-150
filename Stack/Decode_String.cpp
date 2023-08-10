class Solution {
public:
    bool isNumber(const string& s) {
        for (char const &ch : s) {
            if (std::isdigit(ch) == 0) 
                return false;
        }
        return true;
    }
    string decodeString(string s) {
        stack<string> st;
        string answer = "";
        int i = 0;
        while(i < s.size()) {
            if(s[i] != ']') {
                string tmp = "";
                tmp += s[i];
                st.push(tmp);
                i++;
            }
            else {
                string p = "";
                string d = "";
                while(st.top() != "[") {
                    p = st.top() + p;
                    st.pop();
                }
                st.pop();
                while(!st.empty() && isNumber(st.top())) {
                    d = st.top() + d;
                    st.pop();
                }
                int num = stoi(d);
                while(num--) st.push(p);
                i++;
            }
        }
        while(!st.empty()) {
            answer = st.top() + answer;
            st.pop();
        }

        return answer;
    }
};
