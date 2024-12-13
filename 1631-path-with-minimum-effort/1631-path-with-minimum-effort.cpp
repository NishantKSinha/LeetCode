class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //(dist,{row,col})
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        int m = heights[0].size();
        int n = heights.size();
        
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        
        int delrow[] = {-1,+1,0,0};
        int delcol[] = {0,0,-1,+1};
        
        dis[0][0] = 0 ;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
                     
                    if(row == n-1 && col == m-1) return dist;
            for(int i = 0 ; i <4;i++){
                int newrow = delrow[i] + row;
                int newcol = delcol[i] + col;
                
                if(newrow >= 0 && newcol >= 0 && newrow < n && newcol < m){
                    int newdis = max(abs(heights[newrow][newcol]-heights[row][col]) , dist);
                    if(dis[newrow][newcol] > newdis ){
                        dis[newrow][newcol] = newdis;
                        pq.push({dis[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
            
        }
        return 0 ;
        
        
    }
};