class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size()) return true;

        int sIndex = 0, tIndex = 0;
        bool isSub = false;

        while(sIndex < s.size() && tIndex < t.size()) {
            if(s[sIndex] == t[tIndex]) sIndex++;
            tIndex++;

            if(sIndex == s.size()) {
                isSub = true;
                break;
            }
        }

        return isSub;
    }
};
