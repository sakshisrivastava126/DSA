class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n); 
        //bi-directional
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        int ansCity = -1; 
        int minReach = INT_MAX;  //it'll represent ab tak sabse chhota count of cities that can be reached

        for(int start=0; start<n; start++){
            //run dijkstra for each city to calculate cities that min can be reached
            vector<int> dis(n, 1e9);
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //dis,node
            pq.push({0, start});
            dis[start] = 0;

            while(!pq.empty()){
                int currdis = pq.top().first;
                int currnode = pq.top().second;
                pq.pop();

                for(auto it : adj[currnode]){
                    int edgeWeight = it.second;
                    int adjnode = it.first;

                    if(currdis + edgeWeight < dis[adjnode]){
                        dis[adjnode] = currdis + edgeWeight;
                        pq.push({dis[adjnode], adjnode});
                    }
                }
            }
            //counting total no of cities that can be reached within the threashold for each city
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(dis[i] <= distanceThreshold) cnt++;
            }
            //cnt < minReach : nayi minReachable city mil gyi hai
            //(cnt == minReach && start > ansCity) : tie hogya hai toh ab jis city ki value badi h hm wo consider krenge
            if(cnt < minReach || (cnt == minReach && start > ansCity)){
                minReach = cnt;
                ansCity = start;
            }
        }
        return ansCity;
    }
};
