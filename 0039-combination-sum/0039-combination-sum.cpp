class Solution {
public:
    void funct(int indx , int target ,vector<int>& candidates,  vector<vector<int>>&result,vector<int>&ans ){
        if(indx == candidates.size()){
            if(target==0){
                result.push_back(ans);
            }
            return;
        }
        //pickup condition(in this we can pick same index multiple times)
        if(candidates[indx] <=target){
        ans.push_back(candidates[indx]);
         funct(indx ,target - candidates[indx],candidates,result,ans);
        ans.pop_back();
        }
        //not pick
        funct(indx +1 ,target,candidates,result,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        funct(0 , target ,candidates,result ,ans);
        return result;
    }
};