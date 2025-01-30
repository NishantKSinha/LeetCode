class Solution {
public:
    int func(int i ,int j , string &text1 , string &text2 ,vector<vector<int>>& dp){
        //base case
        if(i < 0 || j <0) return 0 ;
        
        if(dp[i][j] != -1) return dp[i][j];

        
        //string match
        if (text1[i] == text2[j]) {  // we are returning so that it goes to further other index not that one 
            return dp[i][j] = 1 + func(i-1,j-1,text1 , text2 ,dp);
        }


        //string not match
        else{
            return dp[i][j] =  max(func(i-1,j,text1,text2,dp),func(i , j-1 ,text1,text2,dp));
        }
    } 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,text1,text2,dp);
    }
};