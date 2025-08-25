// User function Template for C++
class Solution {
  private:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //doing topo sort
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        //creating an array to store distance
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = INT_MAX;
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();  //stack se ek pop kro
            
            //agar elem ka distance h hmpe already then check kro sare adjacency nodes
            
            if(dist[node] != INT_MAX){
                for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dist[node]+wt < dist[v]){
                        dist[v] = dist[node]+wt;
                    }
                }
            }
        }
        //if cannot be reached mark as -1
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
