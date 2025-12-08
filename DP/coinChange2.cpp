#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(i < 0 || amount < 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int pick=0;
        if(amount >= coins[i]) pick = helper(coins, amount - coins[i], i, dp);
        int notPick = helper(coins, amount, i-1, dp);

        return dp[i][amount] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = helper(coins, amount, n-1, dp);
        return ans;
    }
};

//TABULATION
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = 1;

        for(int i=n-1; i>=0; i--){
            for(int j = 1; j<amount+1; j++){
                int pick = 0;
                if(j >= coins[i]) pick = dp[i][j - coins[i]];
                int notPick = dp[i+1][j];

                dp[i][j] = pick+notPick;
            }
        }

        return dp[0][amount];
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        const long long MOD = 1e18;
        vector<long long> dp(amount+1, 0);
        dp[0]=1;

        for(int i=0; i<n; i++){
            for(int j = coins[i]; j<=amount; j++){
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
                
            }
        }

        return dp[amount];
    }
};
