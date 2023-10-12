class Solution {
public:
    void findAndInsert(int index, vector<string>& list, map<pair<string, int>, set<string>>& m) {
        if(m.find({list[0], index}) == m.end()) {
            set<string> tmp;
            for(int j = 1; j < list.size(); j++) tmp.insert(list[j]);
            m[{list[0], index}] = tmp;
        }

        else {
            bool flag = false;
            for(int j = 1; j < list.size(); j++) {
                if(m[{list[0], index}].find(list[j]) != m[{list[0], index}].end()) {
                    flag = true;
                    break;
                }
            }

            if(flag) {
                for(int j = 1; j < list.size(); j++) m[{list[0], index}].insert(list[j]);
            }

            else {
                index++;
                findAndInsert(index, list, m);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        auto pre = accounts;
        while(true) {
            vector<vector<string>> ans;
            map<pair<string, int>, set<string>> m;

            for(int i = 0; i < accounts.size(); i++) findAndInsert(0, accounts[i], m);

            for(auto &k : m) {
                vector<string> t;
                t.push_back(k.first.first);
                for(auto x : k.second) t.push_back(x);
                ans.push_back(t);
            }

            if(pre == ans) break;
            else {
                pre = ans;
                accounts = ans;
            }
        }
        
        return pre;
    }
};
