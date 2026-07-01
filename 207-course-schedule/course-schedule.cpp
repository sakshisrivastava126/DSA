class Solution {
public:
    bool canFinish(int numCour, vector<vector<int>>& preq) {
        if(preq.empty()) return true;
        vector<vector<int>> adj(numCour);
        for(auto it : preq){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }
        vector<int> ind(numCour, 0);
        for(int i=0; i<numCour; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCour; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        int cnt=0;
        vector<int> vis(numCour);
        while(!q.empty()){
            cnt++;
            int node = q.front();
            q.pop();
            vis[node]=1;

            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0 && !vis[it]){
                    q.push(it);
                }
            }

        }
        return cnt==numCour;
    }
};