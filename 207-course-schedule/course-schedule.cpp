class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& preq) {
        if(preq.size()==0) return true;
        vector<vector<int>> adj(nc);
        for(auto it : preq){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ind(nc);
        for(int i=0; i<nc; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<nc; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;

            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }
        return cnt==nc;
    }
};