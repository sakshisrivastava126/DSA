class Solution {
private:
    int helper(vector<int>& nums, int i, int rem, vector<vector<int>>& dp){
        if(i == nums.size())
            return rem == 0 ? 0 : -1e8; 

        if(dp[i][rem] != -1)
            return dp[i][rem];

        // pick
        int pick = nums[i] + helper(nums, i + 1, (rem + nums[i]) % 3, dp);

        // not pick
        int notPick = helper(nums, i + 1, rem, dp);

        return dp[i][rem] = max(pick, notPick);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int maxi=0, sum=0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(3, -1));
        return helper(nums, 0, 0, dp);
    }
};
