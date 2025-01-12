class Solution {
public:
//TC == O(5N) == NOT OPTIMAL SOLUTION
// NOTE ==  WE ARE FINDING ELEMENT INDEXES IN BOTH PSE AND NSE NOT FINDING ACRUAL ELEMENT 
// Function to find Previous Smaller Element (PSE) indices
    vector<int> findPSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
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
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();

        // Find PSE and NSE
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);

        // Calculate the largest rectangle area
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};