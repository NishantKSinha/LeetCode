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
    int height(TreeNode *root){
        if(root == NULL) return 0 ;

        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh , rh);
    }
     
    bool isBalanced(TreeNode* root) {
       
       if(root == NULL) return true;

       int l = height(root->left);
       int r = height(root->right);

       if((l-r) > 1 || (r-l) > 1){
        return false;
       }
       bool left = isBalanced(root->left);
       bool right = isBalanced(root->right);

       if(left == false || right == false) return false;
      
      return true;
      
    }
};