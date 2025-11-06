#include<iostream>
#include<vector>
using namespace std;

//MEMOIZATION
class Solution {
  private:
    int f(vector<int>& arr, int i, int t, vector<vector<int>>& dp){
        if(i==0){
            if(t==0 && arr[i] == 0) return 2;  //for the 1st element if it's 0 we can either pick or not pick it
            if(t==0 || arr[i] == t) return 1;  
            return 0;
        }
        
        if(dp[i][t] != -1) return dp[i][t];
        int pick = 0;
        if (arr[i] <= t) pick = f(arr, i-1, t-arr[i], dp);
        int notPick = f(arr, i-1, t, dp);
        
        return dp[i][t] = pick+notPick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(arr, n-1, target, dp);
    }
};

//TABULATION
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        if (arr[0] == 0) dp[0][0] = 2;  //agar pehla element 0 hai mtlb we can retrun target in 2 ways, either pick it or don't it won't effect
        else dp[0][0] = 1;   //agar pehla element 0 ni h it is still in the 0th column(i.e. target = 0) so we can not pick it that's 1 way

        if (arr[0] != 0 && arr[0] <= target) //agar target se chhota hai pehla element toh dp array me uski position per 1 way to satisfy target
            dp[0][arr[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int k=0; k<=target; k++){
                int notPick = dp[i-1][k];
                int pick = 0;
                if(arr[i] <= k) pick = dp[i-1][k-arr[i]];
                
                dp[i][k] = pick+notPick;
            }
        }
        
        return dp[n-1][target];
    }
};
