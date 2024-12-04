class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //we will first create directed graph which can be done by creating adjacency list
        int V = numCourses;
       vector<vector<int>> adj(V);
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]); //here we have given to take course 0 we have to visit course 1 first
            //if there is vector of pair given instead of vector of vector then we use  adj[it.second].push_back(it.first)
        }
        
        //copy toposort code
        
         vector<int>indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) { //here its adj not change to prerequiste[i] bcz we create adjacency list for directed graph
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo; 
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node); 
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if(topo.size() == V) return true; //means topo sort done so it does not have cycle so we can prerequiste all courses in order
       return false;
    }
};