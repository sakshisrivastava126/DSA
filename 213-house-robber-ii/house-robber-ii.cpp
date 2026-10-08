class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(nums, i+2, dp);
        int skip = solve(nums, i+1, dp);

        return dp[i] = max(pick, skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size()+1, -1);
        vector<int> dp2(nums.size()+1, -1);
        int case1 = solve(nums, 1, dp1);
        nums.pop_back();
        int case2 = solve(nums, 0, dp2);
        return max(case1, case2);
    }
};