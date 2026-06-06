class Solution {
private:
    int helper(vector<int>& nums, int i, int prev, vector<vector<int>>& dp){
        if(i < 0) return 0;
        if(dp[i][prev +1] != -1) return dp[i][prev +1];

        int len = 0;
            len = helper(nums, i-1, prev, dp); 
        if(prev == -1 || nums[i] < nums[prev]) 
            len = max(len, 1+helper(nums, i-1, i, dp));
        return dp[i][prev +1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(nums, n-1, -1, dp);
    }
};