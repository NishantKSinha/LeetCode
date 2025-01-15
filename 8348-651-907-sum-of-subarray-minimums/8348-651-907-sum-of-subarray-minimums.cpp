class Solution {
public:
 //tc == o(5N) sc == o(5N)
 // Function to find Previous Smaller Element (PSE) indices
    vector<int> findPSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
      
    // Function to find Next Smaller Element (NSE) indices
    vector<int> findNSE( vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
         int n = arr.size();
         int total = 0;
         int mod = (1e9+7);
        // Find PSEE(previous smaller eleemnt and equal eleement to avoid edge case we took equal part) and NSE
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);
        for(int i = 0 ; i < n ; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (left*right*1ll*arr[i])%mod)%mod;
        }
        return total;
    }
};