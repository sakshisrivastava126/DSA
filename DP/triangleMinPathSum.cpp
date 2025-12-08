//MEMOIZATION
class Solution {
private:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        int n = triangle.size();
        if(i == n-1) return triangle[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + helper(triangle, i+1, j, dp);
        int diag = triangle[i][j] + helper(triangle, i+1, j+1, dp);

        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(triangle, 0, 0, dp);
    }
};

//TABULATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //we don't have a fixed point to reach at the bottom, so we begin from last row and move up to 0,0
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        //for all values in last row, storing it in dp table
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        //we already calculated value of last row, so we begin from second last and move towards top
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){

                int down = dp[i+1][j]; //same as recursion calculate down and diagonal
                int diag =  dp[i+1][j+1];

                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        return dp[0][0];
    }
};
