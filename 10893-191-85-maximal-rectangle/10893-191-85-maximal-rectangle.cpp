class Solution {
public:
    int findarea(vector<int>& heights){
            int maxarea = 0;
        int n = heights.size();
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
              while(!st.empty() && heights[st.top()] >= heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 :st.top();
                maxarea = max(maxarea,element * (nse - pse -1));   
              }
          st.push(i);
        }

        //some elemnts will left in as it didnot get nse bcz loop ccome to end 
        while(!st.empty()){
            int nse = n;
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(maxarea,element * (nse - pse -1)); 
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n , vector<int>(m));
        //prefix sum
        for(int j = 0 ; j< m ; j++){
            int sum = 0 ;
            for(int i = 0 ; i <n ;i++){
               // sum = sum+matrix[i][j]; we cannot use this bcz mat[i][j] is character so we have to convert in int
                if (matrix[i][j] == '1') {
                    sum += 1; // Increment sum for '1'
               }
                else {
                     sum = 0; // Reset sum for '0'
                }
                psum[i][j] = sum;
            }
        }
        //calculating area
        int maxarea1 = 0 ;
        for(int i = 0 ; i< n ; i++){
            maxarea1 = max(maxarea1,findarea(psum[i]));
        }
        return maxarea1;
    }
};