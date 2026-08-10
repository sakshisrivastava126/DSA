class Solution {
public:
    vector<int> pref;
    int solve(int l, int r, vector<vector<int>>& dp){
        if(l>=r) return dp[l][r] = 0;

        if(dp[l][r] != -1) return dp[l][r];

        return  dp[l][r] = max(pref[r+1]-pref[l+1] - solve(l+1, r, dp), pref[r]-pref[l]-solve(l, r-1, dp));
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        pref.resize(n+1);
        
        for(int i=0; i<n; i++){
            pref[i+1] = pref[i]+stones[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, dp);
    }
};