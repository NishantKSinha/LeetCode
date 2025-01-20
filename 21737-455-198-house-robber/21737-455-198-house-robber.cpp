class Solution {
public:
    //tc = o(2^n)
    int func(int i , vector<int>&nums,vector<int>&dp){
        if(i < 0) return 0 ;
        if(i == 0) return nums[i]; // this is not manadatory but we are manitain structure format

        if(dp[i] !=-1) return dp[i];

        int pick = nums[i] + func(i-2,nums,dp);
        int notpick = 0 + func(i-1,nums,dp);

        return dp[i] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(n-1,nums,dp);
    }
};