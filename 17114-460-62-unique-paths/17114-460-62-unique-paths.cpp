class Solution {
public:
//simple recursion == tc == 2^(m*n) == sc== (path length) == (n-1)+(m-1)
int func(int i , int j,vector<vector<int>>&dp){
    //base-case 
    if(i == 0 && j ==0) return 1;
    if(i < 0 || j < 0) return 0 ;

     if(dp[i][j] != -1) return dp[i][j];
    int left = func(i , j-1,dp);
    int up = func(i-1 , j,dp);
     return dp[i][j] = left + up ;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return func(m-1,n-1 ,dp);
    }
};