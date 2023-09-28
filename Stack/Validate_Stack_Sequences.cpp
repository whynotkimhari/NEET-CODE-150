class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        int len1 = pushed.size(), len2 = popped.size();
        stack<int> st;
        while(i < len1 && j < len2) {
            if(st.empty()) {
                st.push(pushed[i]);
                i++;
            }
            else if(st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i]);
                i++;
            }
        }

        while(j < len2) {
            if(st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else return false;
        }

        return true;
    }
};
