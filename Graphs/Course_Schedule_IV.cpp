class Solution {
public:
    bool dfs(int i, unordered_map<int, unordered_set<int>>& g, unordered_set<int>& visited, vector<int>& learnt) {
        visited.insert(i);
        for(auto &c : g[i]) {
            if(visited.find(c) == visited.end()) {
                visited.insert(c);
                if(!dfs(c, g, visited, learnt)) return false;
            }
            // Because the test say that will not loop exist => Then no need to check "else" case
        }
        if(find(learnt.begin(), learnt.end(), i) == learnt.end()) learnt.push_back(i);
        
        return true;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> g;
        unordered_map<int, int> m;
        unordered_set<int> visited;
        
        set<pair<int,int>> pres;
        vector<int> learnt, ord;
        vector<bool> ans;

        for(auto &pair : prerequisites) {
            g[pair[0]].insert(pair[1]);
            pres.insert({pair[0], pair[1]});
        }

        for(int i = 0; i < numCourses; i++) dfs(i, g, visited, learnt);

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
            
            if(!flag) ord.push_back(id);
        }

        for(int i = 0; i < ord.size(); i++) m[learnt[i]] = ord[i];

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

                            if(l == query[1]) {
                                flag = true;
                                break;
                            }
                        }
                    }
                    q.pop();

                    if(flag) break;
                }

                ans.push_back(flag);
            }
            else ans.push_back(0);
        }

        return ans;
    }
};
