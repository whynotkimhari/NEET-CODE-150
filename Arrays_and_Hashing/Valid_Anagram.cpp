class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<char> char1, char2;
        for(int i = 0; i < s.size(); i++) {
            char1.push_back(s[i]);
            char2.push_back(t[i]);
        }
        sort(char1.begin(), char1.end());
        sort(char2.begin(), char2.end());
        for(int i = 0; i < s.size(); i++) {
            if(char1[i] != char2[i]) return false;
        }
        return true;
    }
};
