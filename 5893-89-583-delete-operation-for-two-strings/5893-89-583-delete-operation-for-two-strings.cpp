class Solution {
public:
      int longestCommonSubsequence(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)); //shifting of index
         
         //fill all first row and 1st column as 0 as base case
         
        for(int i = 0 ; i < n ; i++) dp[i][0] = 0;
        for(int j = 0 ; j <m ; j++) dp[0][j] = 0;
        
        for(int i =1; i <= n ; i++){
          for(int j =1 ; j <= m ; j++){
                
           if(s1[i-1] == s2[j-1]) { // we were doing shifting thats why we take i-1 and j-1
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
           }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        //we have to convert word1 to word2 
        int deletion = word1.length() - longestCommonSubsequence(word1,word2);
        int insertion = word2.length() - longestCommonSubsequence(word1 ,word2);
        int ans = deletion + insertion;
        return ans;
    }
};