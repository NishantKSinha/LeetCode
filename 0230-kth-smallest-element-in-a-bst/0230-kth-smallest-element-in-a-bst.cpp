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
    void solve(TreeNode* root , int k , int &idx , int &ans){
        if(root == NULL){
            return ;
        }
        solve(root->left , k , idx,ans);
        if(k == idx){
            cout<<idx;
            ans = root->val;
            idx++;
            return;
        }
        else{
            idx++;
        }
        solve(root->right , k , idx , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int idx = 1;
        int ans = -1;
        solve(root , k ,idx,ans);
        return ans;
    }
};