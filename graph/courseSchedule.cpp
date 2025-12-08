class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //taking V as total num of edges in the graph
        int V = numCourses;
        vector<int> indegree(V, 0);
        
        //converting prerequisites(edges here) into adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        
        //counting the indegree
        for(int i=0; i<V; i++){
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        
        //pushing the first node in the queue having indegree 0
        int cnt = 0;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                cnt++;
                q.push(i);
            }
        }
        
        //until our q is not empty we will keep on pushing the nodes having indegree 0
        //and removing the node from the queue and decreading the indegree value after every removal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    //counting the number of times we have pushed node in the queue
                    cnt++;
                    q.push(it);
                } 
            }
        }
        //if count is not equal to the number of nodes then we have cyclic graph meaning we cannot finish the courses
        if(cnt != V) return false;
        else return true;
    }
};
