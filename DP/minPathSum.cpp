//MEMOIZATION
class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i==0 && j==0) return grid[0][0]; 
        if(i<0 || j<0) return 1e9;

        if(dp[i][j] != 0) return dp[i][j]; //memoization
        //move up and left while calculating
        int up = grid[i][j] + helper(grid, i-1, j, dp);
        int left = grid[i][j] + helper(grid, i, j-1, dp);

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        return helper(grid, m-1, n-1, dp);
    }
};

//TABULATION
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else{
                    int up = 1e9, left = 1e9;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) curr[0] = grid[0][0];
                else{
                    int up = 1e9, left = 1e9;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return curr[n-1];
    }
};
