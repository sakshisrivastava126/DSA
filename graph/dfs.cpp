class Solution {
  private:
    void dfsSearch(vector<vector<int>>& adj, int node, vector<int> &vis, vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(int it : adj[node]){
            if(vis[it] == 0){  
                dfsSearch(adj, it, vis, ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfsSearch(adj, i, vis, ans);
            }
        }
        return ans;
        
    }
};
