class Solution {
public:
int func(int idx , int target,vector<int>&arr, vector<vector<int>>&dp){
       //base-case == we are going deep to check whether there is any zero elements
       
        if(idx == 0){
           if(target == 0 && arr[0] == target) return 2;
           if(arr[0] == target || target == 0) return 1;
            else return 0;
       }
       
       
       if(dp[idx][target] != -1) return dp[idx][target];
       
       int nottake = func(idx-1,target,arr,dp); //simply call the main fumction
       int take = 0; // if we can't take the taken part bcz target become smaller than
                          //idx value direct return false and no further call will occur
       if(arr[idx] <= target) {
           take = func(idx-1,target-arr[idx],arr,dp);
       }
       return dp[idx][target] = (take + nottake);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int totalsum = 0 ;
        for(int i = 0 ; i<n ; i++) totalsum += arr[i];
       
       if((totalsum-d) < 0 || (totalsum - d) % 2 != 0) return 0;
       int target = (totalsum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(n-1,target,arr,dp); 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};