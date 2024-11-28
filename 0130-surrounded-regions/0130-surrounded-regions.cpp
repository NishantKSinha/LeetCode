class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis , int row,int col,int delrow[],int delcol[]){
        vis[row][col] = 1;
         int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i <4 ; i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
           if(nrow<n && nrow >= 0 && ncol < m && ncol>=0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
               dfs(board,vis,nrow,ncol,delrow,delcol);
           }
        } 
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int delrow[] = {0,0,-1,+1};
        int delcol[] = {+1,-1,0,0};
        
        //traverse fist row and last row
        
        for(int i = 0 ; i < m ; i++){
            //first row
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(board,vis,0,i,delrow,delcol);
            }
            //last row
             if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(board,vis,n-1,i,delrow,delcol);
            }
        }
        //traverse first col and last col
         for(int j = 0 ; j < n ; j++){
            //first col
            if(!vis[j][0] && board[j][0] == 'O'){
                dfs(board,vis,j,0,delrow,delcol);
            }
            //last col
             if(!vis[j][m-1] && board[j][m-1] == 'O'){
                dfs(board,vis,j,m-1,delrow,delcol);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] ='X';
                }
            }
        }
        
    }
};