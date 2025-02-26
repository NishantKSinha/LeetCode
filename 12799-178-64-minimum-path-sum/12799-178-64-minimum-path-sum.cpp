class Solution {
public:
    int func(int i , int j , vector<vector<int>>&grid,vector<vector<int>>&dp){

        if(i == 0 && j==0) return grid[i][j];
        if(i < 0 || j <0) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + func(i-1,j,grid,dp);
        int left = grid[i][j] + func(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);
    }  
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1)); 
        
       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ;j++){
            if(i == 0 && j == 0 ) dp[i][j] = grid[i][j];
            else{
                int up = 1e9;
                if((i-1)>= 0) up= dp[i-1][j] + grid[i][j];
                int left = 1e9;
                if((j-1)>=0) left = dp[i][j-1] + grid[i][j];

                dp[i][j] = min(up,left);

            }
        }
       }
       return dp[n-1][m-1];
    }
};