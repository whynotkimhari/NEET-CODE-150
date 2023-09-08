/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> L;
        vector<int> R;
        q.push(root->left);
        while(!q.empty()) {
            auto n = q.front();
            if(n) {
                L.push_back(n->val);
                q.push(n->left);
                q.push(n->right);
            }
            else L.push_back(-101);
            
            q.pop();
        }
        q.push(root->right);
        while(!q.empty()) {
            auto n = q.front();
            if(n) {
                R.push_back(n->val);
                q.push(n->right);
                q.push(n->left);
                
            }
            else R.push_back(-101);
            
            q.pop();
        }

        if(L.size() != R.size()) return false;

        for(int i = 0; i < L.size(); i++) {
            if(L[i] != R[i]) return false;
        }

        return true;
    }
};
