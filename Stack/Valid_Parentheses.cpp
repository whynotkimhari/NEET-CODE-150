class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            if(s[i] == ')') {
                if(st.size() == 0) return false;
                if(st.top() == '(') st.pop();
                else if(st.top() == '{' || st.top() == '[') return false;
            }

            if(s[i] == '}') {
                if(st.size() == 0) return false;
                if(st.top() == '{') st.pop();
                else if(st.top() == '(' || st.top() == '[') return false;
            }

            if(s[i] == ']') {
                if(st.size() == 0) return false;
                if(st.top() == '[') st.pop();
                else if(st.top() == '{' || st.top() == '(') return false;
            }
        }

        if(st.size() != 0) return false;

        return true;
    }
};
