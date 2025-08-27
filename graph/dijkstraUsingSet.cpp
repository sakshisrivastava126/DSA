// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V); // node -> {adjNode, weight}
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //dis, node
        set<pair<int,int>> st;
        vector<int> dis(V, 1e9); //initialize all with infinity
        
        dis[src] = 0; //dis from src is 0
        st.insert({0,src}); //push src node
        
        while(!st.empty()){
            //pop and traverse adj nodes
            auto it = *(st.begin());
            int currDis = it.first;
            int currNode = it.second;
            st.erase(it);
            
            for(auto it : adj[currNode]){
                int edgeWeigh = it.second;
                int adjNode = it.first;
                
                if(currDis + edgeWeigh < dis[adjNode]){ //if newDis is less push in the set
                if(dis[adjNode] != 1e9){
                    st.erase({dis[adjNode], adjNode});
                }
                    dis[adjNode] = currDis + edgeWeigh;
                    st.insert({dis[adjNode],adjNode});
                }
            }
            
        }
        return dis;
    }
};
