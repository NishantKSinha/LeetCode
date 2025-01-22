class Solution {
public:
    //memoization == tc ==(m*n) == sc== (path length) + o(m*N) == (n-1)+(m-1)+O(N*M)
    int func(int i , int j,vector<vector<int>>&dp ,vector<vector<int>>& obstacleGrid){
    //one extra case
    if(i >= 0 && j >=0 && obstacleGrid[i][j] == 1) return 0;
    //base-case 
    if(i == 0 && j ==0) return 1;
    if(i < 0 || j < 0) return 0 ;

     if(dp[i][j] != -1) return dp[i][j];
    int left = func(i , j-1,dp,obstacleGrid);
    int up = func(i-1 , j,dp,obstacleGrid);
     return dp[i][j] = left + up ;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return func(m-1,n-1 ,dp,obstacleGrid);
    }
};