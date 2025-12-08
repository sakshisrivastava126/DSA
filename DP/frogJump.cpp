int f(int indx, vector<int>& heights, vector<int> dp){
    if(indx==0) return 0;
    if(dp[indx] != -1) return dp[indx]; //to store same values we have calculated before
    int left = f(indx-1, heights, dp) + abs(heights[indx] - heights[indx-1]);
    int right = INT_MAX;
    if(indx>1)
    right = f(indx-1, heights, dp) + abs(heights[indx] - heights[indx-2]);

    return dp[indx]=min(left,right);
}

int frogJump(int n, vector<int>& heights){
    vector<int> dp(n+1, -1);
    f(n-1,heights,dp);
}
