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
    void mapping(TreeNode* root , unordered_map<TreeNode*,TreeNode*>&parenttracker){
       queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                    parenttracker[temp->left] = temp;
                }
                 if(temp->right != NULL){
                    q.push(temp->right);
                    parenttracker[temp->right] = temp;
                }           
        }        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parenttracker;
        mapping(root , parenttracker);
        
        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*>q;
        
         q.push(target);
         visited[target] = true;
        int currlevel = 0;
         while(!q.empty()){
             int size = q.size();
              if(currlevel == k) break;
             
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();
               q.pop();
                if(temp->left != NULL && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right != NULL && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parenttracker[temp] && !visited[parenttracker[temp]]){
                    q.push(parenttracker[temp]);
                    visited[parenttracker[temp]] = true;
                }
            }
            currlevel++;
             
         }
         vector<int>result;
         while(!q.empty()){
             TreeNode* temp = q.front();
             q.pop();
             result.push_back(temp->val);
             
         }
        return result;
        
    }
};