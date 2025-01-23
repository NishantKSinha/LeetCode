class Solution {
public:
    int func(int i , int j , vector<vector<int>>&triangle,vector<vector<int>>&dp){
        int n = triangle.size();
        int m = triangle.size();
        //base case==last row
       if(i == n-1){
      
       return dp[i][j] = triangle[n-1][j];
        
       } 
       if(dp[i][j] != -1) return dp[i][j];
       int down = triangle[i][j] + func(i+1,j,triangle,dp);
       int rightdig = triangle[i][j] + func(i+1,j+1,triangle,dp);
       return dp[i][j] = min(down,rightdig);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,triangle,dp);
    }
};