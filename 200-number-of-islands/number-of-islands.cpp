class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j){
        vis[i][j] = 1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx < m && nx >=0 && ny < n && ny >= 0 && !vis[nx][ny] && grid[nx][ny] == '1'){
                dfs(grid, vis, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};