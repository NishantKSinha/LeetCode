class Solution {
    private:
            void dfs(int row,int col ,int newcolor, int inicolor,int delrow[],int delcol[],vector<vector<int>>&                      image,vector<vector<int>>&ans){
                ans[row][col] = newcolor;//mark initial row and col with newcolor
                int n = image.size();
                int m = image[0].size();
                for(int i = 0 ; i<4;i++){
                    int newrow = row + delrow[i];
                    int newcol = col + delcol[i];
                    if(newrow >= 0 && newrow< n && newcol >=0 && newcol < m && image[newrow][newcol]== inicolor
                      && ans[newrow][newcol] != newcolor){
                        dfs(newrow,newcol,newcolor,inicolor,delrow,delcol,image,ans);
        
                    }
                }
            }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int inicolor = image[sr][sc];//src==rowno,sc==colno,we store initialcolor
        vector<vector<int>> ans = image; //we copy all data of image matrix in  ans matrix as we dont want to alter the data
        
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,+1,-1};
        
        dfs(sr,sc,color,inicolor,delrow,delcol,image,ans);     
        return ans;
        
    }
};