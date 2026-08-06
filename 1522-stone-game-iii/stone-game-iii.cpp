class Solution {
public:
    int n;
    vector<int> sv;
    long long solve(bool turn, int i, vector<vector<long long>>& dp){
        if(i==n) return 0;

        if(dp[turn][i] != -1) return dp[turn][i];

        long long res = 0;
        long long score=0;

        if(turn) res = LLONG_MIN;
        else res = LLONG_MAX;

        for(int x=1; x<= min(n-i, 3); x++){
            score += sv[i+x-1];
            if(turn){
                res = max(res, score+solve(!turn, i+x, dp));
            }
            else{
                res = min(res, solve(!turn, i+x, dp)-score);
            }
        }
        return dp[turn][i] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        sv = stoneValue;
        vector<vector<long long>> dp(2, vector<long long>(n, -1));
        int ans = solve(1, 0, dp);

        if(ans>0) return "Alice";
        else if(ans==0) return "Tie";
        else return "Bob";
    }
};