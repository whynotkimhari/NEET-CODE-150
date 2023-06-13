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
    int Height(TreeNode* root) {
        if(!root) return 0;
        else return 1 + max(Height(root->right), Height(root->left));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(abs(Height(root->left) - Height(root->right)) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
