class Solution {
public:
    bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;  // Both strings exhausted
        if (i < 0 && j >= 0) return false; // Pattern exhausted but string remains
        
        if (j < 0 && i >= 0) { // String exhausted, check if pattern is only '*'
            for (int k = 0; k <= i; k++) {
                if (S1[k] != '*') return false;
            }
            return true;
        }

        // If already computed, return the value
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match or pattern has '?'
        if (S1[i] == S2[j] || S1[i] == '?') {
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
        }
        else if (S1[i] == '*') {
            // '*' can match zero or more characters
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        }
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        // Create a DP table to memoize results
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return wildcardMatchingUtil(p, s, n, m, dp);
    }
};
