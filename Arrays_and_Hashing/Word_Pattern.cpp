class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<char*> vt;
        map<string, set<char>> m;
        map<char, set<string>> m2;
        bool is = true;

        char * cstr = new char [s.length()+1];
        strcpy (cstr, s.c_str());

        char * p = strtok (cstr," ");
        while (p!=0) {
            vt.push_back(p);
            p = strtok(NULL," ");
        }

        if(vt.size() != pattern.size()) return 0;

        for(int i = 0; i < pattern.size(); i++) {
            string z(vt[i]);
            m[z].insert(pattern[i]);
            m2[pattern[i]].insert(z);
        }

        for(auto &key: m) {
            if(key.second.size() > 1) return false;
        }
        for(auto &key: m2) {
            if(key.second.size() > 1) return false;
        }
        return is;
    }
};
