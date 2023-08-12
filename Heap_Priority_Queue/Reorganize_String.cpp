class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";

        int size = s.size();
        while(size--) ans += " ";

        map<char, int> MMap;
        for(auto &c: s) MMap[c]++;

        vector<pair<int,char>> vt;
        for(auto &key: MMap) vt.push_back({key.second, key.first});
        sort(vt.begin(), vt.end(), greater<pair<int,char>>());
        
        int id = 0, cnt = 0;
        bool even = true;

        while(cnt < vt.size()) {
            auto& key = vt[cnt];
            if(even) {
                while(true) {
                    if(id <= ans.size() - 1) {
                        ans[id] = key.second;
                        id+=2;
                        key.first--;
                        if(key.first < 1) {
                            cnt++;
                            break;
                        }
                    }
                    else {
                        even = false;
                        id = 1;
                        if(key.first < 1) cnt++;
                        break;
                    }
                }
            }
            else {
                while(key.first--) {
                    ans[id] = key.second;
                    id+=2;
                }
                cnt++;
            }
        }

        for(int i = 0; i < s.size() - 1; i++) {
            if(ans[i] == ans[i+1]) return "";
        }
        
        return ans;
    }
};
