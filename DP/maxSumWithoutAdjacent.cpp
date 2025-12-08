// User function template for C++
class Solution {
  private:
    int helper(vector<int>& arr, int indx, vector<int> &dp){
        //base case: handling negative and 0 index cases
        if(indx == 0) return arr[indx];
        if(indx < 0) return 0;
        //memoization : if we have already calculated use it
        if(dp[indx] != -1) return dp[indx];
        
        //pick element & skip the one just before it
        int pick = arr[indx] + helper(arr, indx-2, dp);
        
        //we do not pick the element that means we can pick the one just before it.
        int notPick = 0 + helper(arr, indx-1, dp);
        
        return dp[indx] = max(pick, notPick);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, n-1, dp);
    }
};
