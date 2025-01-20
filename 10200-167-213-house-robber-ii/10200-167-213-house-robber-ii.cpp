class Solution {
public:
    // Time Complexity: O(n), Space Complexity: O(n)
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) return nums[start]; // Only one house in range

        vector<int> dp(n, -1);
        dp[0] = nums[start]; // Base case: First house in range
        for (int i = 1; i < n; i++) {
            int pick = nums[start + i];
            if (i > 1) {
                pick += dp[i - 2];
            }
            int notpick = 0 +  dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n - 1]; // Maximum money that can be robbed in range
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;          // Edge case: No houses to rob
        if (n == 1) return nums[0];    // Edge case: Only one house to rob

        // Robbing houses from 0 to n-2 and 1 to n-1
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};
