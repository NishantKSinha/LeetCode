class Solution {
public:
       vector<int> generaterow(int rowno){
        vector<int>ans;
          long long res = 1 ; 
         ans.push_back(res);     // for col0

         for(int col = 1 ; col < rowno;col++){
              res = res * (rowno-col);
              res = res / (col);
              ans.push_back(res);
          }
          return ans;
       }
       
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> result;

      for(int i = 1 ; i<= numRows ; i++){
        result.push_back(generaterow(i));

      }
      return result;
    }
};