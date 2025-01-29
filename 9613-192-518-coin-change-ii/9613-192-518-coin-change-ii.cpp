class Solution {
public:
 int func(int idx , int target,vector<int>&arr, vector<vector<int>>&dp){
       //base-case == we are going deep to check whether there is any zero elements
       
        if(idx == 0){
           if(target % arr[0] == 0) return 1;
            else return 0;
       }
       
       
       if(dp[idx][target] != -1) return dp[idx][target];
       
       int nottake = func(idx-1,target,arr,dp); //simply call the main fumction
       int take = 0; // if we can't take the taken part bcz target become smaller than
                          //idx value direct return false and no further call will occur
       if(arr[idx] <= target) {
           take = func(idx,target-arr[idx],arr,dp);
       }
       return dp[idx][target] = (take + nottake);
    }
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,amount,coins,dp);
         return ans ;
    }
};