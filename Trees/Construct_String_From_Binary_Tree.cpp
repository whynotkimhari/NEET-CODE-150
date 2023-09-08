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
    // d == 0: left
    // d == 1: right
    void travel(TreeNode* root, string& str, int d, TreeNode* sib) {
        if(!root) {
            if(!d && sib) str += "()";
            return;
        }

        if(d != 2) str += "(";
        str += to_string(root->val);

        travel(root->left, str, 0, root->right);
        travel(root->right, str, 1, root->left);
        
        if(d != 2) str += ")";
    }

    string tree2str(TreeNode* root) {
        string str = "";
        travel(root, str, 2, nullptr);
        return str;
    }
};
