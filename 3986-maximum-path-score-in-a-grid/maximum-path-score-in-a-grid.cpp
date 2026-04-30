class Solution {
private:
    int score(vector<vector<int>>& grid, vector<int>& cost, int k, int i, int j, int m, int n, vector<vector<vector<int>>>& dp){
        if(k < 0) return -1e9;
        if(i >= m || j>= n) return -1e9;

        int cellCost = cost[grid[i][j]];
        if (k - cellCost < 0) return -1e9;
        k = k - cellCost;
        if(i == m-1 && j==n-1) return grid[i][j];

        if(dp[i][j][k] != -1) return dp[i][j][k];
        int right = -1e9, down = -1e9;
        
            if(j+1 < n ) right = score(grid, cost, k, i, j+1, m, n, dp);
            if(i+1 < m ) down = score(grid, cost, k, i+1, j, m, n, dp);
        
        return dp[i][j][k] = grid[i][j] + max(right, down);
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cost(3);
        cost = {0, 1, 1};
        int ans = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        ans = score(grid, cost, k, 0, 0, m, n, dp);
        if(ans < 0) return -1;
        else return ans;
    }
};