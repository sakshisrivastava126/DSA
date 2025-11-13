#include<iostream>
#include<vector>
using namespace std;

//MEMOIZATION
class Solution {
private:
    int robber(vector<int>& nums, int i, int end, vector<int>& dp){
        int n = nums.size();

        //WE move from front towards end
        if(i>end) return 0;
        if(i == end) return nums[i];

        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + robber(nums, i+2, end, dp); //pick 

        int notPick = robber(nums, i+1, end, dp); //not pick

        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        //as we have to run 2 cases we use 2 dp arrays
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(robber(nums, 1, n-1, dp1), robber(nums, 0, n-2, dp2));
    }
};
