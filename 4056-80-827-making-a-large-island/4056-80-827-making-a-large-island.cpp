class DisjointSet {
   
public:
 vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
     private:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        //s-1
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) continue;
                else{
                    int delrow[] = {-1,+1,0,0};
                    int delcol[] = {0,0,-1,+1};
                    for(int idx = 0 ; idx <4 ; idx++){
                        int newrow = i + delrow[idx];
                        int newcol = j + delcol[idx];
                        if(isValid(newrow,newcol,n,n) && grid[newrow][newcol]==1){
                            int nodeno = i * n + j;
                            int adjnodeno = newrow * n + newcol;
                            ds.unionBySize(nodeno , adjnodeno);
                        }
                    }
                }
            }
        }
        //s-2==storing ultimate unique parent to set
        int mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) continue;
                else{
                    set<int > st;
                    int delrow[] = {-1,+1,0,0};
                    int delcol[] = {0,0,-1,+1};
                    for(int idx = 0 ; idx <4 ; idx++){
                        int newrow = i + delrow[idx];
                        int newcol = j + delcol[idx];
                        if(isValid(newrow,newcol,n,n) && grid[newrow][newcol]==1){
                           
                            int adjnodeno = newrow * n + newcol;
                            st.insert(ds.findUPar(adjnodeno));
                        }
                    }
                    int sizetotal = 0 ;
                    for(auto it : st){
                        sizetotal += ds.size[it];
                    }
                    mx = max(mx,sizetotal +1);
                }
            }
        }
        //s-3 let suppose all cell are 1 
        for(int cell =0;cell<n*n;cell++){
            mx = max(mx,ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};