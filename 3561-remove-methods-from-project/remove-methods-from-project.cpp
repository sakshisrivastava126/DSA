class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        vector<vector<int>> adj(n);
        for(auto it : invo){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        vector<int> ans;
        dfs(k, vis, adj);

        for(auto it : invo){
            if(!vis[it[0]] && vis[it[1]]){
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};