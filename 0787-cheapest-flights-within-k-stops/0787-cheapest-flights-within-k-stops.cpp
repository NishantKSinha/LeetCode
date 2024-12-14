class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //we will create directed graph
        
      vector<vector<pair<int, int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]}); //node1->node2,edgewt
        }
        //stopsno , node ,dist
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0 ;
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            
            if(stop > k) break;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                
                if(edw + dis < dist[adjnode] && stop <= k){
                    dist[adjnode] = edw+dis;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};