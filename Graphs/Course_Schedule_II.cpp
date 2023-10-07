class Solution {
public:
    bool dfs(int i, map<int, set<int>>& g, set<int>& visited, vector<int>& learnt) {
        visited.insert(i);
        for(auto &c : g[i]) {
            if(visited.find(c) == visited.end()) {
                visited.insert(c);
                if(!dfs(c, g, visited, learnt)) return false;
            }
            else {
                if(find(learnt.begin(), learnt.end(), c) == learnt.end()) {
                    visited.clear();
                    return false;
                }
                
            }
        }
        if(find(learnt.begin(), learnt.end(), i) == learnt.end()) {
            learnt.push_back(i);
        }
        
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> g;
        set<int> visited;
        vector<int> learnt;

        for(auto &pair : prerequisites) {
            g[pair[0]].insert(pair[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, g, visited, learnt)) {
                learnt.clear();
                return learnt;
            }
        }

        return learnt;
    }
};
