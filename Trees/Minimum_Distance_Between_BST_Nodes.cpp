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
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()) {
            auto n = q.front();
            v.push_back(n->val);
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            q.pop();
        }

        int len = v.size();
        int min = INT_MAX;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                min = min < abs(v[i] - v[j]) ? min : abs(v[i] - v[j]);
            }
        }
        
        return min;
    }
};
