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
    TreeNode* mapping( TreeNode* root ,unordered_map< TreeNode*, TreeNode*>&parent , int start){
       queue< TreeNode*>q;
       q.push(root);
        TreeNode* res;
       while(!q.empty()){
            TreeNode* temp = q.front();
           if(temp->val == start){
               res = temp;
              
           }
            q.pop();
           if(temp->left != NULL){
               q.push(temp->left);
               parent[temp->left] = temp;
           }
           if(temp->right != NULL){
               q.push(temp->right);
               parent[temp->right] = temp;
           }
       }
        return res;
   }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map< TreeNode*, TreeNode*>parent;
         TreeNode* newNode = mapping(root, parent , start);
        
        unordered_map< TreeNode*,bool>visited;
        queue< TreeNode*>q;
       
        q.push(newNode);
        visited[newNode] = true;
        int timeburn = -1 ;
        while(!q.empty()){
            int size = q.size();
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
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
            timeburn = timeburn + 1;
            
        }
        return timeburn;
        
    }
};