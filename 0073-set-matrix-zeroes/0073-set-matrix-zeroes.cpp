class Solution {
public:
    
  
    void setZeroes(vector<vector<int>>& matrix) {
        //bettter==tc==(2*n*m)  sc==o(c) + o(r)
        int r = matrix.size();
        int c = matrix[0].size();
        
     // Creating extra vectors for marking columns and rows
    vector<int> col(c, 0); // Initializing col vector with 0s
    vector<int> row(r, 0); // Initializing row vector with 0s
    
        for(int i =0 ; i < r;i++){
            for(int j =0 ; j <c ; j++){
                if(matrix[i][j] == 0){
                    col[j] = -1;
                    row[i] = -1;
                }
            }
        }
        for(int i =0 ; i < r;i++){
            for(int j =0 ; j <c ; j++){
                if(row[i] == -1 || col[j] == -1){
                    matrix[i][j] = 0;
                }
                
            }
        }
    }
};