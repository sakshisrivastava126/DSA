class Solution {
public:
    int n, sum=0;
    bool solve(vector<int>& nums, int i, int &curr, vector<vector<int>>& dp){
        if(i >= n) {
            if(curr == sum-curr) dp[i][curr] = true;
            else return dp[i][curr] = false;
        }

        if(dp[i][curr] != -1) return dp[i][curr];

        bool skip = solve(nums, i+1, curr, dp);

        curr += nums[i];
        bool pick = solve(nums, i+1, curr, dp);
        curr -= nums[i];

        return dp[i][curr] = pick || skip;
    }
    bool canPartition(vector<int>& nums) {
        for(auto i : nums) sum += i;
        n = nums.size();
        int curr=0;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(nums, 0, curr, dp);
    }
};