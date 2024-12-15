class Solution {
public:
    //take distance in long long so that test case will pass
    int countPaths(int n, vector<vector<int>>& roads) {
        //forming undirected graph node->node , edgewt
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }
         priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq; 
        vector<long long>dist(n,1e18),ways(n,0);
        dist[0] = 0 ;
        ways[0] =1;
        pq.push({0,0}); // dist,node
        int mod = 1e9 +7;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                long long edw = it.second;
                
                //this is first time i am coming with short distance
                
                if(dis+edw < dist[adjnode]){
                    dist[adjnode] = dis+edw;
                    pq.push({dis+edw , adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(dis+edw == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};