class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>>q;//{dist,{row,col}}
        int n = grid.size();
        int m = grid[0].size();
        
         // Check if the start or end is blocked
    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
     
    if(n==1 && m==1 && grid[0][0]==0) return 1;    
        
        //now declaring dist vector-2d
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});
        
        int delrow[] = {+1,-1,0,0,+1,+1,-1,-1};
        int delcol[] = {0,0,-1,+1,+1,-1,-1,+1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i = 0 ; i < 8;i++){
               int newrow = row + delrow[i] ;
                int newcol = col +delcol[i];
                
                if(newrow >= 0 && newrow < n && newcol>=0 && newcol < m
                  && grid[newrow][newcol] == 0 && 1+dis < dist[newrow][newcol]){
                    
                    dist[newrow][newcol] = 1+dis;
                
                    
                      // If the target cell is reached, return the distance
                     if(newrow == n-1 && newcol == m-1) return 1+dis;
                
                      q.push({1+dis,{newrow,newcol}});
                }   
            }
        }
        return -1;
        
        
    }
};