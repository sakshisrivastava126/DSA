class Solution {
public:
    void dfs(vector<vector<int>>& isCon, vector<int>& vis, int node){
        vis[node]=1;
        for(int i=0; i<isCon.size(); i++){
            if(!vis[i] && isCon[node][i]){
                dfs(isCon, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int cnt=0;
        int m = isCon.size();
        int n = isCon[0].size();
        vector<int> vis(m, 0);

        for(int i=0; i<m; i++){
            if(!vis[i]){
                cnt++;
                dfs(isCon, vis, i);
            }
        }
        return cnt;
    }
};