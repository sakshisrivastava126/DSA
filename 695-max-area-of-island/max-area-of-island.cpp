class Solution {
public:
    int m, n;
    int maxi = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int &cnt){
        vis[i][j] =1;
        cnt++;
        maxi = max(maxi, cnt);

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int nx = i+ dx[k];
            int ny = j+ dy[k];
            if(nx <m && nx >=0 && ny <n && ny >=0 && !vis[nx][ny] && grid[nx][ny] == 1){
                dfs(grid, vis, nx, ny, cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int cnt=0;
                    dfs(grid, vis, i, j, cnt);
                }
            }
        }
        return maxi;
    }
};