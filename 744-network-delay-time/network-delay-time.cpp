class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        // int n = times[0].size();
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto t : times){
            int u = t[0];
            int v = t[1];
            int tt = t[2];
            adj[u].push_back({v, tt});
        }

        int ans=-1;
        int cnt=0;
        vector<int> cost(n+1, 1e9);
        cost[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int t_max = 0;

        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int nei_t = it.second;
                int nei = it.first;
                if(cost[nei] > nei_t + t){
                    cost[nei] = nei_t + t;
                    pq.push({cost[nei], nei});
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(cost[i] == 1e9) return -1;
            ans = max(ans, cost[i]);
        }
        return ans;
    }
};