/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        set<Node*> traveled;
        queue<Node*> q;
        map<int, Node*> z;
        map<Node*, vector<Node*>> g;

        q.push(node);
        traveled.insert(node);

        while(!q.empty()) {
            auto top = q.front();
            for(auto &n: top->neighbors) {
                if(traveled.find(n) == traveled.end()) {
                    q.push(n);
                    traveled.insert(n);
                }

                if(z.find(n->val) == z.end()) {
                    z[n->val] = new Node(n->val);
                }

                if(z.find(top->val) == z.end()) {
                    Node* x = new Node(top->val);
                    z[top->val] = x;

                    vector<Node*> tmp; tmp.push_back(z[n->val]);
                    g[x] = tmp;
                }
                
                else {
                    g[z[top->val]].push_back(z[n->val]);
                } 
            }
            q.pop();
        }


        for(auto key: g) {
            key.first->neighbors = key.second;
        }

        if(z.size() >= 1) node = z[1];
        else node = new Node(1);

        return node;
    }
};
