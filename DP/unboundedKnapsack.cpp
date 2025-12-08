#include<iostream>
#include<vector>
using namespace std;

//MEMOIZATION
class Solution {
  private:
    int helper(vector<int>& val, vector<int>& wt, int cap, int idx, int n, vector<vector<int>>& dp){
        if(cap==0) return 0;
        if(idx < 0) return 0;
        
        if(dp[idx][cap] != -1) return dp[idx][cap];
        int pick = 0, notPick = 0;
        if(wt[idx] <= cap) pick = val[idx] + helper(val, wt, cap-wt[idx], idx, n, dp);
        notPick = helper(val, wt, cap, idx-1, n, dp);
        
        return dp[idx][cap] = max(pick, notPick);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        int ans = helper(val, wt, capacity, n-1, n, dp);
        return ans;
    }
};

//TABULATION
// class Solution {
//   public:
//     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
//         int n = val.size();
//         vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
        
        
//         for(int i=val.size() - 1; i>=0; i--){
//             for(int j=1; j<capacity+1; j++){
//                 int pick = 0;
//                 if(j >= wt[i]) pick = val[i] + dp[i][j-wt[i]];
//                 int notPick = dp[i+1][j];
                
//                 dp[i][j] = max(pick, notPick);
//             }
//         }
        
//         return dp[0][capacity];
//     }
// };

int main(){
    Solution sol;
    vector<int> val(4);
    vector<int> wt(4);
    val = {10, 40, 50, 70};
    wt = {1,3,4,5};
    int ans = sol.knapSack(val, wt, 8);
    cout << ans << endl;

    return 0;
}
