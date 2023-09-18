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
private:  
  bool assign;
  TreeNode* root;
public:
    Solution() {
      assign = false;
      root = nullptr;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!this->assign) {
          this->assign = true;
          this->root = root;
        }

        if(!root) {
          this->root = new TreeNode(val);
          return this->root;
        }

        else {
          if(root->left && root->right) {
            if(val > root->val) return insertIntoBST(root->right, val);
            else return insertIntoBST(root->left, val);
          }
          else if(root->left && !root->right) {
            if(val > root->val) root->right = new TreeNode(val);
            else return insertIntoBST(root->left, val);
          }
          else if(!root->left && root->right) {
            if(val > root->val) return insertIntoBST(root->right, val);
            else root->left = new TreeNode(val);
          }
          else {
            if(val > root->val) root->right = new TreeNode(val);
            else root->left = new TreeNode(val);
          }
        }
        
        return this->root;
    }
};
