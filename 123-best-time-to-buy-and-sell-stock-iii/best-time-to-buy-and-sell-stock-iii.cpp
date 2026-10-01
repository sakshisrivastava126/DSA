class Solution {
public:
    //skip, buy or sell 
    int maxi = 0;
    int solve(vector<int>& p, int i, int cnt, bool buy, vector<vector<vector<int>>>& dp){
        if(i>=p.size() || cnt <= 0) {
            return 0;
        }

        if(dp[i][cnt][buy] != -1) return dp[i][cnt][buy];

        //skip
        int skip = solve(p, i+1, cnt, buy, dp);

        int take=0;
        if(buy){
            take = -p[i] + solve(p, i+1, cnt, !buy, dp);
        }
        else{
            take = p[i] + solve(p, i+1, cnt-1, !buy, dp);
        }
        return dp[i][cnt][buy] = max(take, skip);
    }
    int maxProfit(vector<int>& prices) {
        int curr=0;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(prices, 0, 2, true, dp);
        // return maxi;
    }
};