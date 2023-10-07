class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<int, set<int>> g;
        set<pair<int,int>> sp;
        int cnt = 0;

        for(auto &pair : connections) {
            sp.insert({pair[0], pair[1]});
            g[pair[0]].insert(pair[1]);
            g[pair[1]].insert(pair[0]);
        }

        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            auto f = q.front();
            visited[f] = true;

            for(auto &c: g[f]) {
                if(!visited[c]) {
                    q.push(c);
                    if(sp.find({f, c}) != sp.end()) cnt++;
                }
            }

            q.pop();
        }

        return cnt;
    }
};
