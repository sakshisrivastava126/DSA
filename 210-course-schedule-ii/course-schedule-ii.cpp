class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> indegree(V, 0);

        vector<vector<int>> adj(V); 
        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        int cnt=0;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                cnt++;
                q.push(i);
                ans.push_back(i);
            } 
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    cnt++;
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(cnt == V) return ans;
        else return {};
    }
};