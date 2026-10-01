#define ll long long
class Solution {
public:
    //buy kr rakha hai then sell krna hi padega
    //else buy bhi kr skte and sell mtlb price add bhi kr skte and subtract bhi
    ll dp[1005][505][3];
    ll solve(vector<int>& p, int k, int i, int buy){
        if(i >= p.size()|| k == 0) {
            if(buy == 0)
                return 0;
            return LLONG_MIN / 2;
        }

        if(dp[i][k][buy] != -1)
            return dp[i][k][buy];

        ll skip = solve(p, k, i+1, buy);
        ll take=LLONG_MIN / 2;;

        if(buy==0){ 
            ll c1 = p[i] + solve(p, k, i+1, 2); //sell
            ll c2 = -p[i] + solve(p, k, i+1, 1); //buy
            take = max(c1, c2);
        }
        else if(buy==1){ //need to sell
            take = p[i] + solve(p, k-1, i+1, 0); 
        }
        else{ 
            take = -p[i] + solve(p, k-1, i+1, 0);
        }

        return dp[i][k][buy] = max(take, skip);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, k, 0, 0);
    }
};