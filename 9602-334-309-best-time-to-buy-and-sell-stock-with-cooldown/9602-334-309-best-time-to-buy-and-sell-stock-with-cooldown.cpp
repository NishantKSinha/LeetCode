class Solution {
public:
    int func(int idx , int buy, int n ,vector<int>& prices,vector<vector<int>>& dp ){
        //basecase
        if(idx >= n) return 0 ; // we put greater sign bcz if idx == n-1 and idx+2 == n+1 i.e out of bound

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        //buycase
        if(buy == 1){
            int take = -prices[idx] + func(idx+1,0,n,prices,dp);
            int nottake = 0 + func(idx+1 , 1 , n ,prices,dp);
            profit = max(take,nottake);
        }
        else{// means we have to sell
            int take = +prices[idx] + func(idx+2,1,n,prices,dp); // minor change == idx+2 instead of idx+1
            int nottake = 0 + func(idx+1 , 0 , n ,prices,dp);
            profit = max(take,nottake);
        }
         return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
     vector<vector<int>>dp(n,vector<int>(2,-1));//2 size bcz=>0 means we dont take or buy and 1 means we take or buy
        return func(0,1,n,prices,dp);
    }
};