class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        string base = "abcdefghijklmnopqrstuvwxyz";
        map<char,char> MMap;
        for(int i = 0; i < base.size(); i++) {
            MMap[order[i]] = base[i];
        }

        vector<string> trans(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                words[i][j] = MMap[words[i][j]];
                trans[i][j] = MMap[trans[i][j]];
            }
            
        }

        sort(trans.begin(), trans.end());

        for(int i = 0; i < words.size(); i++) {
            if(words[i] != trans[i]) return false;
        }
        return true;
    }
};
