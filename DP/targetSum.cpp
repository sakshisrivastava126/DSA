#include<iostream>
#include<vector>
using namespace std;
//this question basically means divide array into two sums such that difference is target

//MEMOIZATION
// class Solution {
// private:
//     int helper(vector<int>& nums, int i, int t, int n, vector<vector<int>>& dp){
//         if(i==0){
//             if(t==0 && nums[i] == 0) return 2;
//             if(t==0 || nums[i] == t) return 1;
//             return 0;
//         }
//         if(dp[i][t] != -1) return dp[i][t];
//         int pick = 0;
//         if(nums[i] <= t) pick = helper(nums, i-1, t-nums[i], n, dp);
//         int notPick = helper(nums, i-1, t, n, dp);
//         return dp[i][t] = pick + notPick;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int cnt = 0;
//         int sum = 0;
//         for(int it: nums){
//             sum += it;
//         }
        
//         if((sum+target)%2 != 0 || sum+target < 0) return 0;
//         int t = (sum+target)/2;
//         vector<vector<int>> dp(n, vector<int>(t+1, -1));
//         int ans = helper(nums, n-1, t, n, dp);
//         return ans;
//     }
// };

//TABULATION
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        for(int it: nums){
            sum += it;
        }
        if((sum+target)%2 != 0 || sum+target < 0) return 0; //handling odd cases and sum+target = negative case

        int t = (sum+target)/2;  
        vector<vector<int>> dp(n, vector<int>(t+1, 0));

        if(nums[0] == 0)    dp[0][0] = 2; //agar pehla element 0 hai then usse pick kro ya na kro it will give same target
        else    dp[0][0] = 1; //agar 0 ni h then mat kro pick = 1way

        if(nums[0] != 0 && nums[0] <= t)    dp[0][nums[0]] = 1; //ek element include kr k kya sum = target kra ja skta hai? haa agar target = element ho toh

        for(int i=1; i<n; i++){
            for(int j=0; j<=t; j++){
                int pick = 0;
                if(nums[i] <= j) pick = dp[i-1][j-nums[i]]; //current target se chhoti ho value then pick only
                int notPick = dp[i-1][j];
                dp[i][j] = pick + notPick;
            }
        }

        int ans = dp[n-1][t];
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr(5);
    arr = {1,1,1,1,1};
    int ans = sol.findTargetSumWays(arr, 3);
    cout << ans;

    return 0;
}
