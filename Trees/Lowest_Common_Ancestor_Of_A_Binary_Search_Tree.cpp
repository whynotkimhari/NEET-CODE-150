/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;

        while(true) {
            if((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val)) {
                break;
            }
            
            if(p->val <= root->val && q->val <= root->val) {
                root = root->left;
                ans = root;
                continue;
            }

            if(p->val >= root->val && q->val >= root->val) {
                root = root->right;
                ans = root;
                continue;
            }
        }

        return ans;
    }
};
