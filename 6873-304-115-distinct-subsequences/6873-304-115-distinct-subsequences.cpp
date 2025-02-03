class Solution {
public:
     int countUtil(string &s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;

    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)   return dp[ind1][ind2];

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        return dp[ind1][ind2] = (leaveOne + stay) ;
    } else {
        // If characters don't match, just leave one character in s1 and continue matching s2
        return dp[ind1][ind2] = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }
}
   int numDistinct(string s, string t) {
   int n = s.size();
   int m = t.size();
   vector<vector<int>> dp(n, vector<int>(m, -1));
    return countUtil(s, t, n- 1, m - 1, dp);

    }
};