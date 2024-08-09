

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
         int left = height(root->left );
        int right = height(root->right );
        int ans = 1 + max(left , right);
        return ans;
    }
    void dia(TreeNode* root, int &diameter){
          if(root == NULL) return ;
        
        int lh = height(root->left);
        int rh = height(root->right );
        int ans1 = lh + rh;
        diameter=max(diameter , ans1);
        dia(root->left,diameter);
        dia(root->right,diameter);
        return ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int diameter=0;
      dia(root,diameter);
      return diameter;
      
    }
};
