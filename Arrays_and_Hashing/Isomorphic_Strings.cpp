class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,set<char>> m1, m2;

        for(int i = 0; i < s.size(); i++) {
            m1[s[i]].insert(t[i]);
            m2[t[i]].insert(s[i]);
        }

        for(auto&key: m1) if(key.second.size() > 1) return false;
        for(auto&key: m2) if(key.second.size() > 1) return false;
        
        return true;
    }
};
