class Solution {
public:
    //we are storing the max height of the smaller side in the dp 
    //and the dp states are the difference and the index
    int solve(vector<int>& rods, int diff, int i, vector<vector<int>>& dp){
        if(i==rods.size()){
            if(diff==0) return 0;
            else return -1e9;
        }

        if(dp[diff][i] != -1) return dp[diff][i];
        
        //we are taking rod in the set 1 and adding the rod won't help the shorter side
        int case1 = solve(rods, diff+rods[i], i+1, dp);

        //we are taking rod in set 2 and adding the rod to the shorter side
        int case2 = min(rods[i], diff) + solve(rods, abs(diff-rods[i]), i+1, dp);
        
        //we dont use the rod
        int case3 = solve(rods, diff, i+1, dp);

        return dp[diff][i] = max({case1, case2, case3});
    }
    int tallestBillboard(vector<int>& rods) {
        int sum =0;
        for(auto it : rods) sum += it; 
        
        vector<vector<int>> dp(sum+1, vector<int>(rods.size()+1, -1));
        return solve(rods, 0, 0, dp);
        
    }
};