//MEMOIZATION METHOD
class Solution {
private:
    int helper(int i, int j, vector<vector<int>> &dp){
        //base case
        if(i==0 && j==0) return 1; //reached destination
        if(i<0 || j<0) return 0;  //check if we are out of bounds

        //check if we have already calculated that value
        if(dp[i][j] != -1) return dp[i][j];
        //move up and left
        int up = helper(i-1,j, dp);
        int left = helper(i, j-1, dp);

        return dp[i][j] = up+left;
    }    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp);
    }
};

//TABULATION : SC -> O(size of row * size of column)
class Solution { 
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0] = 1; //base case of recursion in dp
                else{
                    int up=0, left=0;
                    //moving up and left making sure we dont go out of bounds
                    if(i>0) up = dp[i-1][j]; //above cell
                    if(j>0) left = dp[i][j-1]; //cell on left
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//DP + SPACE OPTIMIZATION : SC -> O(size of column) 
class Solution { 
public:
    int uniquePaths(int m, int n) {
        //we actually only need previous row and previous column data
        vector<int> prev(m,0); //dp array to store data of previous row
        vector<int> curr(n,0); //this stores the current row

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) curr[0] = 1; 
                else{
                    int up=0, left=0;
                    if(i>0) up = prev[j]; //above row data
                    if(j>0) left = curr[j-1]; //previous column data
                    curr[j] = up+left;
                }
            }
            prev = curr; //change the previous 
        }
        return curr[n-1];
    }
};

