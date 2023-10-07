class Solution {
public:
    bool dfs(int i, map<int, set<int>>& g, set<int>& visited, set<int>& learnt) {
        visited.insert(i);
        for(auto &c : g[i]) {
            if(visited.find(c) == visited.end()) {
                visited.insert(c);
                if(!dfs(c, g, visited, learnt)) return false;
            }
            else {
                if(learnt.find(c) == learnt.end()) {
                    visited.clear();
                    return false;
                }
                
            }
        }
        learnt.insert(i);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> g;
        set<int> learnt, visited;

        for(auto &pair : prerequisites) {
            g[pair[0]].insert(pair[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, g, visited, learnt)) return false;
        }

        return true;
    }
};
