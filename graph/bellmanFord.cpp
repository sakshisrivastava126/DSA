// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        dis[src] = 0;
        
        for(int i=0; i<V-1; i++){
                for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
        //check negative cycle : if change is noticed in nth iteration means negative cycle is present
        for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                    return {-1};   //so return -1
                }
        }
        return dis;
    }
};
