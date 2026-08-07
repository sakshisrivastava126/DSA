class Solution {
public:
    int n; vector<int> pref;
    int solve(vector<int>& sv, int fstidx, int lstidx, vector<vector<int>>& dp){
        if(fstidx == lstidx) return 0;

        if(dp[fstidx][lstidx] != -1) return dp[fstidx][lstidx];

        int l =0, r=0; int ans=0;
        for(int i=fstidx; i<lstidx; i++){
            if(fstidx == 0){
                l = pref[i];
            }
            else l = (pref[i]-pref[fstidx-1]);
            r = (pref[lstidx] - pref[i]);

            if(l > r){
                ans = max(ans, r + solve(sv, i+1, lstidx, dp));
            }
            else if(l < r){
                ans = max(ans, l + solve(sv, fstidx, i, dp));
            }
            else{
                ans = max(ans, l + max(solve(sv, i+1, lstidx, dp), solve(sv, fstidx, i, dp)));
            }
        }
        return dp[fstidx][lstidx] = ans;
    }
    int stoneGameV(vector<int>& sv) {
        n = sv.size();
        pref.resize(n);
        pref[0] = sv[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+sv[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(sv, 0, n-1, dp);
    }
};