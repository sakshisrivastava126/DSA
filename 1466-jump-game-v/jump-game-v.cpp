class Solution {
public:
    int n;
    int d;
    int solve(vector<int>& arr, int i, vector<int>& dp){
        int maxi = 1;
        if(dp[i] != -1) return dp[i];

        for(int x=1; i+x < n && x <=d; x++){
            if(arr[i+x] >= arr[i]) break;
            maxi = max(maxi, 1+solve(arr, i+x, dp));
        }

        for(int x=1; i-x >= 0 && x <=d; x++){
            if(arr[i-x] >= arr[i]) break;
            maxi = max(maxi, 1+solve(arr, i-x, dp));
        }

        return dp[i] = maxi;
    }
    int maxJumps(vector<int>& arr, int dd) {
        n = arr.size();
        d = dd;
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int ans = 0;
            vector<int> dp(n, -1);
            ans = solve(arr, i, dp);
            maxi = max(maxi, ans);
        }

        return maxi;
    }
};