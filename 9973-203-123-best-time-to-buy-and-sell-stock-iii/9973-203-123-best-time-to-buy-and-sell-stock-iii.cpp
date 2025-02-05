class Solution {
public:
    int func(int idx , int buy,int count, int n ,vector<int>& prices,vector<vector<vector<int>>>& dp ){
        //basecase
        if(idx == n || count == 0) return 0 ;

        if(dp[idx][buy][count] != -1) return dp[idx][buy][count];

        int profit = 0;
        //buycase
        if(buy == 1){
            int buy1 = -prices[idx] + func(idx+1,0,count,n,prices,dp);
            int notbuy1 = 0 + func(idx+1 , 1 ,count, n ,prices,dp);
            profit = max(buy1,notbuy1);
        }
        else{// means we have to sell
            int sell = +prices[idx] + func(idx+1,1,count-1,n,prices,dp); //count will decrease when we sell 
            int notsell = 0 + func(idx+1 , 0 ,count ,n,prices,dp);
            profit = max(sell,notsell);
        }
         return dp[idx][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int coun = 2; //0,1,2 == size 3
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
                                 //2 size bcz=>0 means we dont take or buy and 1 means we take or buy
        return func(0,1,2,n,prices,dp);
    }
};