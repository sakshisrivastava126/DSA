class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, int n){
        vis[node] = 1;
          for(int j = 0; j < n; j++){
            if(adj[node][j] == 1 && !vis[j]){
                dfs(j, adj, vis, n);
            }
        }
    }    

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, isConnected, vis, n);
            }
        }
        return cnt;
    }
};
