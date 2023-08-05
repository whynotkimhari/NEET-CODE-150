class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]!='*')
            st.push(s[i]);
            else if(s[i]=='*' && !st.empty())
            st.pop();

        } 
        if(st.empty())
        return ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
