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
    void func(TreeNode* root,TreeNode* &prev, bool &f){
        if(root == NULL){
            return ;
        }
        func(root->left , prev , f);
        if(prev != NULL && root->val <= prev->val){
            f = false;
            return;
        }
        else{
            prev = root;
        }
        func(root->right , prev , f);
    }
    bool isValidBST(TreeNode* root) {
        bool f =true;
        TreeNode* prev = NULL;
        func(root , prev , f);
        return f;
    }
};