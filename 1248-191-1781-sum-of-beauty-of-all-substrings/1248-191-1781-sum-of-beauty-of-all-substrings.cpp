class Solution {
public:
    int beautySum(string s) {
          int sum = 0;
        unordered_map<char, int> mpp;

        for (int i = 0; i < s.length(); i++) {
            mpp.clear();

            for (int j = i; j < s.length(); j++) {
                mpp[s[j]]++;  // Update frequency of the character

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Correct iteration over the map
                for (auto &p : mpp) {
                    maxi = max(maxi, p.second);
                    mini = min(mini, p.second);
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};