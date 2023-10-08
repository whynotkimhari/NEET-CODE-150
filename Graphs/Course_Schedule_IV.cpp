// TLE: will fix soon...
class Solution {
public:
    bool dfs(int i, map<int, set<int>>& g, set<int>& visited, vector<int>& learnt) {
        visited.insert(i);
        for(auto &c : g[i]) {
            if(visited.find(c) == visited.end()) {
                visited.insert(c);
                if(!dfs(c, g, visited, learnt)) return false;
            }
            // Because the test say that will not loop exist => Then no need to check "else" case
        }
        if(find(learnt.begin(), learnt.end(), i) == learnt.end()) {
            learnt.push_back(i);
        }
        
        return true;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int, set<int>> g;
        set<int> visited;
        set<pair<int,int>> pres;
        vector<int> learnt;
        vector<int> ord;
        vector<bool> ans;
        map<int, int> m;

        for(auto &pair : prerequisites) {
            g[pair[0]].insert(pair[1]);
            pres.insert({pair[0], pair[1]});
        }

        for(auto k: g) {
            cout << k.first << ": ";
            for(auto v: k.second) cout << v << " ";
            cout << endl;
        }

        for(int i = 0; i < numCourses; i++) {
            dfs(i, g, visited, learnt);
        }

        for(auto &c: learnt) {
            cout << c << " ";
        }
        cout << endl;

        if(!prerequisites.size()) {
            for(auto &query : queries) ans.push_back(false);
            return ans;
        }
        int id = 0;
        ord.push_back(id);

        for(int i = 1; i < learnt.size(); i++) {
            bool flag = false;
            for(auto &z : g[learnt[i]]) {
                if(pres.find({learnt[i], z}) != pres.end()) {
                    ord.push_back(++id);
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
             {
                // id = 0;
                ord.push_back(id);
            }
        }

        for(int i = 0; i < ord.size(); i++) {
            m[learnt[i]] = ord[i];
        }

        for(auto &c: ord) {
            cout << c << " ";
        }
        cout << endl;


        for(auto &query : queries) {
            if(m[query[0]] > m[query[1]]) {
                queue<int> q;
                q.push(query[0]);
                set<int> visited;
                bool flag = false;

                while(!q.empty()) {
                    auto f = q.front();
                    visited.insert(f);

                    for(auto l: g[f]) {
                        if(visited.find(l) == visited.end()) {
                            q.push(l);

                            if(l == query[1]) flag = true;
                        }
                    }
                    q.pop();
                }

                ans.push_back(flag);
            }
            else ans.push_back(0);
        }

        return ans;
    }
};
