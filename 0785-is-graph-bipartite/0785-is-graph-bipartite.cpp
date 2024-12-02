class Solution {
public:
  /*  bool bfs(int start, vector<vector<int>>& graph, vector<int>& col){
        queue<int> q;
        q.push(start);
        col[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(col[it] == -1){
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]) return false;
            }
        }
        return true;
    }*/
 bool dfs(int node, vector<vector<int>>& graph, vector<int>& col) {
        // Traverse each node and check the adjacency
        for (auto it : graph[node]) {
            if (col[it] == -1) { // If unvisited
                col[it] = !col[node]; // Assign opposite color to the adjacent node
                if (!dfs(it, graph, col)) { // Recursively visit the neighbor
                    return false;
                }
            } else if (col[it] == col[node]) { // If the same color is found on adjacent nodes
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V, -1); // Initialize all vertices as uncolored (-1)

        for (int i = 0; i < V; i++) { // Traverse all nodes
            if (col[i] == -1) { // If the node is uncolored
                col[i] = 0; // Assign an initial color (0 or 1)
                if (!dfs(i, graph, col)) { // Start DFS from this uncolored node
                    return false;
                }
            }
        }
        return true;
    }
};