class Solution {
  public:

    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> vis(adj.size(), 0);
        queue<int> q;
        vector<int> bfs;
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            bfs.push_back(curr);
            //push
            for(int node : adj[curr]){
                if(vis[node] == 0){
                    vis[node] = 1;
                    q.push(node);
                }
            }
        }
        return bfs;
    }
};
