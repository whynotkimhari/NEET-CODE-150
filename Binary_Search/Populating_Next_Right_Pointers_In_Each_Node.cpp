/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        else {
            return 1 + max(maxDepth(root->right), maxDepth(root->left));
        }
    }

    Node* connect(Node* root) {
        queue<Node*> mainQ, subQ;

        subQ.push(root);
        int cnt = maxDepth(root);
        while(cnt--) {
            Node* pre = nullptr;
            while(!subQ.empty()) {
                mainQ.push(subQ.front());
                subQ.pop();
            }

            while(!mainQ.empty()) {
                auto el = mainQ.front();
                if(!pre) pre = el;
                else {
                    pre->next = el;
                    pre = pre->next;
                }

                mainQ.pop();
                if(el && el->left) subQ.push(el->left);
                if(el && el->right) subQ.push(el->right);
            }
        }
        return root;
    }
};
