class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end) {
            if(!iswalnum(s[start])) {
                start++;
                continue;
            }
            if(!iswalnum(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) return false;
            if(tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            }
        }
        return true;
    }
};
