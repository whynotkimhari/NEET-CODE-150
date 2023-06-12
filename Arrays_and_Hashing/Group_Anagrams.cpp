class Solution {
public:
    static pair<vector<char>,string> toVector(string &str) {
        vector<char> chars;
        for(int i = 0; i < str.size(); i++) {
            chars.push_back(str[i]);
        }
        sort(chars.begin(), chars.end());
        return {chars, str};
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> ms;
        vector<vector<string>> ans;

        for(auto str: strs) {
            auto p = toVector(str);
            ms[p.first].push_back(p.second);
        }

        for(auto &key: ms) {
            vector<string> v;
            for(auto &s : key.second) v.push_back(s);
            ans.push_back(v);
        }
        return ans;
    }
};
