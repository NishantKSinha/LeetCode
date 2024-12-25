class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
           //we are using floyd warshal 
        //here we have to create 2d matrix bcz in floyd warshal question first matrix was already created and here the edges contain information about single direction and also not about every node
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));//or INT_MAX
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];  //undirected 
        }
        for(int i =0 ; i <n ;i++) dist[i][i] = 0;
        //algo
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int cityno = -1;
        int citycount = n;
        for(int i = 0 ; i < n ; i++){
            int count = 0 ;
            for(int j = 0 ; j < n ; j++){
                if(dist[i][j] <= distanceThreshold) count++;
            }
            if(count <= citycount) {
                citycount = count;
                cityno = i;
            }
        }
        return cityno;
    }
};