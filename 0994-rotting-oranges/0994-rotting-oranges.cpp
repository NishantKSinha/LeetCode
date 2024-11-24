class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); //grid row size
        int m = grid[0].size(); // grid col size
        //for{{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0 ;
                }
            }
        }
        
        int time = 0 ;
        int drow[] = {-1,+1,0,0};
        int dcol[] = {0 , 0 , +1, -1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tym = q.front().second;
            time = max(time ,tym);
            q.pop();
            
            for(int i = 0 ; i <4 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol]==1 ){
                    vis[nrow][ncol] =2;
                    q.push({{nrow ,ncol},tym+1});
                }
            }
        }
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 2 && grid[i][j] ==1) return -1;
            }
        }
        return time;
        
        
    }
};