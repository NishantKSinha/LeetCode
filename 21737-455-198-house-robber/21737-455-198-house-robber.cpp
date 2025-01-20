class Solution {
public:
    //tc = o(n) === sc == o(n)+o(n)
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

       
        
        dp[0] = nums[0] ;

        for(int i = 1 ; i < n ; i++){
            int pick =  nums[i] ;
            if(i > 1){
              pick = pick + dp[i-2];
            }   
             int notpick = 0 + dp[i-1]; // no need to add here bcz i start from 1 and 1-1 = 0 so dont tensed
            
            dp[i] = max(pick,notpick); 
        }
        return dp[n - 1] ;
    }
};