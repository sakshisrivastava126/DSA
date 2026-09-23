class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int m, n;
    int unq_id=2;

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        vis[i][j]= unq_id;
        int sz = 1;

        for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx < m && nx >=0 && ny < n && ny >=0 && !vis[nx][ny] && grid[nx][ny] == 1){
                sz += dfs(grid, vis, nx, ny);
            }
        }
        return sz;
    }
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    unq_id += 1;
                    int sz = dfs(grid, vis, i, j);
                    mp[unq_id] = sz;
                    ans = max(ans, sz);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int> ids;
                    int curr=1;

                    for(int k=0; k<4; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(nx < m && nx >=0 && ny < n && ny >=0 && grid[nx][ny] != 0 && vis[nx][ny] != 0){
                            int id = vis[nx][ny];
                            if(!ids.count(id)){
                                curr += mp[id];
                            }
                            ids.insert(id);
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};