#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parentCount(n, 1);
        int cnt = 0;

        int maxi = 1;
        for(int i=1; i<n; i++){
            cnt = 0;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                }
                maxi = max(maxi, dp[i]);
                if(dp[i] == dp[j]) parentCount[i] = parentCount[j] +1;
            }
        }

        for(int it : dp) {
            cout << it << " ";
        }
        cout << endl;
        for(int it : parentCount) {
            cout << it << " ";
        }
        cout << endl;

        int ans = 0;
        for(int i=0; i<n; i++){
            if(maxi == dp[i]) ans += parentCount[i];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr(5);
    arr = {1,3,5,4,7};
    int ans = sol.findNumberOfLIS(arr);
    cout << ans;
    return 0;
}
