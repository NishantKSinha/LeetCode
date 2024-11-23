class Solution {
public:
    void bfs(int node , vector<int>adj[] ,vector<int>&vis){
    //     int vis[isConnected.size()+1] = {0};
        // initially we always mark first node i.e 0 as visited and push into queue
        vis[node] = 1;
        queue<int>q;
        q.push(node);
        
        //vector<int> bfs;
        
        while(!q.empty()){
            int snode = q.front();
            q.pop();
           // bfs.push_back(node);
            
            //now we will check node neighbour from adjacency list
            
            for(auto it : adj[snode]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //we change adj matrix to adj list ...we can also use adj matrix but its more easy method
        
        vector<int>adj[isConnected.size()+1];
        
        for(int i = 0 ; i <isConnected.size() ; i++){
             for(int j = 0 ; j <isConnected.size() ; j++){
                 
                 if(isConnected[i][j] == 1 && i != j){
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                 }
             }
        }
        int N = isConnected.size();
       // int vis[N+1] = {0};
        vector<int> vis(N + 1, 0);
        int cnt = 0 ;
        
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!vis[i]){
                cnt++;
                bfs(i , adj,vis);
            }
        }
        return cnt;
    }
};