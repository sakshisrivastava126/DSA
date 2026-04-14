class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> ty;
    int tar;
    int solve(int i, int marks, vector<vector<int>> &dp){
        if(tar == marks) return 1;
        if(i >= ty.size()) return 0;
        if(marks > tar) return 0;

        if(dp[i][marks] != -1) return dp[i][marks];

        int take = 0;
        int cnt = ty[i][0];
        int ms = ty[i][1];
        for(int c=0; c <= cnt; c++){
            if(tar >= c*ms + marks){
                take = (take + solve(i+1, c*ms + marks, dp)%mod)%mod;
            }
        }
        return dp[i][marks] = take;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        tar = target;
        ty = types;
        
        vector<vector<int>> dp(types.size(), vector<int>(tar+1, -1));
        return solve(0, 0, dp)%mod;
    }
};