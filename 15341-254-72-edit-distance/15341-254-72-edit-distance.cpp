class Solution {
public:
int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
    // Base cases
    if (i < 0) //means we have to insert in s1 to match
        return j + 1;
    if (j < 0) // means we have to delete in s2 to match
        return i + 1;


    if (dp[i][j] != -1)   return dp[i][j];

    // If character match
    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices:
    // 1. Replace the character at S1[i] with the character at S2[j]
    // 2. Delete the character at S1[i]
    // 3. Insert the character at S2[j] into S1
    else
        return dp[i][j] =  min(1 + editDistanceUtil(S1, S2, i - 1, j - 1, dp),  //replace
                                  min(1 + editDistanceUtil(S1, S2, i - 1, j, dp),   //delete
                                     1+  editDistanceUtil(S1, S2, i, j - 1, dp)));  //insert
}

    int minDistance(string word1, string word2) {
          int n = word1.size();
         int m = word2.size();

        // Create a DP table to memoize results
      vector<vector<int>> dp(n, vector<int>(m, -1));

         // Call the utility function with the last indices of both strings
           return editDistanceUtil(word1, word2, n - 1, m - 1, dp);
    }
};