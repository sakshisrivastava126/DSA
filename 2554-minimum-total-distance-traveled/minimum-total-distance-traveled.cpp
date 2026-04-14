#define ll long long
class Solution {
public:
    vector<int> rob, pos;
    vector<vector<int>> fact;
    ll dist = LLONG_MAX;

    ll solve(int i, int j, vector<vector<ll>>& dp){
        if(i >= rob.size()) {
            return 0;
        }
        if(j >= pos.size()) return LLONG_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        ll notTake = solve(i, j+1, dp);
        ll take = LLONG_MAX;

        if(solve(i+1, j+1, dp) != LLONG_MAX)
            take = solve(i+1, j+1, dp) + abs(pos[j]-rob[i]);

        return dp[i][j] = min(take, notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) { 
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        rob = robot;
        fact = factory;
        
        for(auto it : factory){
            int p = it[0];
            int limit = it[1];
            for(int i=0; i<limit; i++){
                pos.push_back(p);
            }
        }
        vector<vector<ll>> dp(robot.size(), vector<ll>(pos.size(), -1));
        return solve(0, 0, dp);
    }
};