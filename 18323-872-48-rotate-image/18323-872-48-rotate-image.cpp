class Solution {
public:
void reverse(vector<int>& arr){
    int n = arr.size();
    int i = 0 , j = n-1;
    while(i < j ) {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
   
}
    //tc == 0(n^2) ==sc =0(1) == approach == first transpose the whole matric and then reverse every row
    void rotate(vector<vector<int>>& matrix) {
          int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
       }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i]);  //or directly write==reverse(matrix[i].begin(), matrix[i].end());
        
    
    }
 }
};