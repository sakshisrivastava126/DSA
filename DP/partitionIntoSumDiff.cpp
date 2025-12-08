class Solution {   
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int it: nums) totalSum += it; 

        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        dp[0][0] = true;
        if (nums[0] <= totalSum) dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int t=0; t<=totalSum; t++){
                bool notPick = dp[i-1][t];
                bool pick = false;
                if(t >= nums[i]){
                    pick = dp[i-1][t - nums[i]];
                }
                dp[i][t] = pick || notPick;
            }
        }

        int mini = 1e9;
        for(int s1=0; s1<=totalSum/2; s1++){
            if(dp[n-1][s1]){
                int s2 = totalSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};
