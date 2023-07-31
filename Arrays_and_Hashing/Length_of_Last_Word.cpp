class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<char*> st;
        char * cstr = new char [s.length()+1];
        strcpy (cstr, s.c_str());

        char * p = strtok (cstr," ");
        while (p!=0) {
            st.push(p);
            p = strtok(NULL," ");
        }
        string z(st.top());
        return z.size();
    }
};
