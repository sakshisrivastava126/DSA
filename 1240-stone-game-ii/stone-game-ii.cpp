class Solution {
public:
    int n;
    int solve(vector<int>& piles, int m, int i, bool turn, vector<vector<vector<int>>>& dp){
        if(i==n) return 0;

        if(dp[m][i][turn] != -1) return dp[m][i][turn];

        int res=0;
        if(turn) res = -1;
        else res = INT_MAX;
        int score=0;

        for(int x=1; x<= min(2*m, n-i); x++){
            score += piles[i+x-1];
            if(turn){
                res = max(res, score + solve(piles, max(m,x), i+x, !turn, dp));
            }
            else{
                res = min(res, solve(piles, max(m, x), i+x, !turn, dp));
            }
        }
        return dp[m][i][turn] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(2*n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return solve(piles, 1, 0, 1, dp);
    }
};