// Solution 1 kind of slow, but it is still accepted
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

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int i = 0; i < pow(2, 2 * n); i++) {
            string s = "";
            int e = i;
            for(int j = 0; j < 2 * n; j++) {
                if(e%2 == 1) s = s + "(";
                else s = s + ")";
                e /= 2;
            }
            if(isValid(s)) ans.push_back(s);
        }
        return ans;
    }
};
