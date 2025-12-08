class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int trans = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(trans+1, 0)));

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=1; k<=2; k++){
                 if(j == 0)
                        dp[i][j][k] = max(-prices[i] + dp[i+1][1][k], dp[i+1][0][k]); //buy, didn't buy
                    else
                        dp[i][j][k] = max(prices[i] + dp[i+1][0][k-1], dp[i+1][1][k]); //sell, didn't sell
                }
                
            }
        }
        return dp[0][0][trans];
    }
};
