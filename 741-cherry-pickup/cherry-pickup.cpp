class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid, int i1, int i2, int j1, vector<vector<vector<int>>>& dp){
        int j2 = i1+j1-i2;
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || j2 < 0) return -1e9;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e9;

        if (i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1)
            return grid[i1][j1];

        if(dp[i1][i2][j1] != -1) return dp[i1][i2][j1];

        int cherries=0;
        if(i1==i2 && j1==j2){
            cherries = grid[i1][j1];
        }
        else{
            cherries = grid[i1][j1] + grid[i2][j2];
        }

        int case1 = solve(grid, i1+1, i2, j1, dp);
        int case2 = solve(grid, i1+1, i2+1, j1, dp);
        int case3 = solve(grid, i1, i2+1, j1+1, dp);
        int case4 = solve(grid, i1, i2, j1+1, dp);

        int best = max({case1, case2, case3, case4});

        if (best <= -1e8) return dp[i1][i2][j1] = -1e9;

        return dp[i1][i2][j1] = best+cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = solve(grid, 0, 0, 0, dp);
        return max(0, ans);
    }
};