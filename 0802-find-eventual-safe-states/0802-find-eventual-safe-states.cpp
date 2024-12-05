class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjRev[V];
          vector<int>indeg(V,0);
        
        //here its in i->it and  we will convert into it->i
       for(int i = 0 ; i<V;i++){ 
          for(auto it: graph[i]){
            adjRev[it].push_back(i);
            indeg[i]++;  
          }
       }    
        queue<int>q;
        vector<int>safenode;
       for(int i = 0 ; i<V;i++){
           if(indeg[i]==0){
               q.push(i);
           }
       } 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            
            for(auto it:adjRev[node]){
                    indeg[it]--;//its bcz after node poping out that node edge has tobe delete from its neighbour
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};