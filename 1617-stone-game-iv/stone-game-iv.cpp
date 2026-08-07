class Solution {
public:
    bool solve(int n, vector<int>& dp){
        if(n==0) return false;
        if(dp[n] != -1) return dp[n];

        int i=1;
        while(i*i <= n){
            if(!solve(n-i*i, dp)){
                return dp[n] = true;
            }
            i++;
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};