class Solution {
public:
    int func(int idx , int buy, int n ,vector<int>& prices,vector<vector<int>>& dp,int fee ){
        //basecase
        if(idx == n) return 0 ;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        //buycase
        if(buy == 1){
            int take = -prices[idx] + func(idx+1,0,n,prices,dp,fee);
            int nottake = 0 + func(idx+1 , 1 , n ,prices,dp,fee);
            profit = max(take,nottake);
        }
        else{// means we have to sell
            int take = +prices[idx] + func(idx+1,1,n,prices,dp,fee) - fee; // here we subtract fee question demand
            int nottake = 0 + func(idx+1 , 0 , n ,prices,dp,fee);
            profit = max(take,nottake);
        }
         return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
     vector<vector<int>>dp(n,vector<int>(2,-1));//2 size bcz=>0 means we dont take or buy and 1 means we take or buy
        return func(0,1,n,prices,dp,fee);
    }
};