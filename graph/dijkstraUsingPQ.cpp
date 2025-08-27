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
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(V, INT_MAX); //initialize all with infinity
        
        dis[src] = 0; //dis from src is 0
        pq.push({0,src}); //push src node
        
        while(!pq.empty()){
            //pop and traverse adj nodes
            int currDis = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            for(auto it : adj[currNode]){
                int edgeWeigh = it.second;
                int adjNode = it.first;
                
                if(currDis + edgeWeigh < dis[adjNode]){ //if newDis is less push in the pq
                    dis[adjNode] = currDis + edgeWeigh;
                    pq.push({dis[adjNode],adjNode});
                }
            }
            
        }
        return dis;
    }
};
