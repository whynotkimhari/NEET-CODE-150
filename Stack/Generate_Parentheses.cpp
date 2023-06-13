// Solution 1 kind of slow, but it is still accepted
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            if(s[i] == ')') {
                if(st.size() == 0) return false;
                if(st.top() == '(') st.pop();
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

## Solution 2: better than 1
class Solution {
private:
    vector<string> ans;
    string st;

public:
    void backTracking(int open, int close, int n) {
        if(open == close && close == n) {
            this->ans.push_back(st);
            return;
        }
        if(open < n) {
            this->st.push_back('(');
            backTracking(open + 1, close, n);
            this->st.pop_back();
        }
        if(open > close) {
            this->st.push_back(')');
            backTracking(open, close + 1, n);
            this->st.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backTracking(0, 0, n);
        return this->ans;
    }
};
