class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int minSize = INT_MAX;

        for(auto &str : strs) {
            if(minSize > str.size()) minSize = str.size();
        }
        string answer = "";

        for(int i = 0; i < minSize; i++) {
            char checkChar = strs[0][i];
            bool isPass = true;

            for(auto &str : strs) {
                if(str[i] != checkChar) {
                    isPass = false;
                    break;
                }
            }

            if(!isPass) break;
            else {
                answer = answer + checkChar;
            }
        }

        return answer;
    }
};
