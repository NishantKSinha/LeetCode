class Solution {
public:
    int find(vector< vector<int>>&mat,int m , int n , int mid){
        int index = -1;
        int maxi = -1;
        for(int i = 0 ; i < m;i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n -1;
        
        while(low <= high){
            int mid = (high+low)/2;
            int maxindex = find(mat,m,n,mid);
            
            int rightelement = mid+1 < n ? mat[maxindex][mid + 1] : -1;
             int leftelement = mid-1 >= 0 ? mat[maxindex][mid - 1] : -1;
            
            if(mat[maxindex][mid] > leftelement && mat[maxindex][mid] > rightelement) return {maxindex,mid};
            else if(mat[maxindex][mid] < leftelement) high = mid-1;
            else if (mat[maxindex][mid] < rightelement) low = mid+1;
            else high = mid-1; //see question 9 for this to understand
        }
        return{-1,-1};
    }
};