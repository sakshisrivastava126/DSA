//MEMOIZATION
class Solution {
private:
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;
        if(i==n-1 ) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];
        int down = matrix[i][j] + helper(matrix, i+1, j, dp);
        int diaL = matrix[i][j] + helper(matrix, i+1, j-1, dp);
        int diaR = matrix[i][j] + helper(matrix, i+1, j+1, dp);

        return dp[i][j] = min({down, diaL, diaR});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++) {
            mini = min(mini, helper(matrix, 0, j, dp));
        }
        return mini;
    }
};

//TABULATION
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        //last row will remain same
        for(int j=0; j<n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        //moving from bottom to top
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                //if its last row it will remain same
                if(i == n-1) dp[i][j] = matrix[i][j];
                else{
                    int down = 1e9, diaL = 1e9, diaR = 1e9;
                    //go in all possible directions
                    down = dp[i+1][j];
                    if(j>0) diaL = dp[i+1][j-1];
                    if(j+1< n && i+1<n) diaR = dp[i+1][j+1];

                    dp[i][j] = matrix[i][j] + min({down, diaL, diaR});
                }
            }
        }

        // compare the top cells of row 0
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};
