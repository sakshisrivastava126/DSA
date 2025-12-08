class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        //backtracking and assigning each node ultimate parent so whenever we travel next, hame firse na find krna pade up
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        //dono ka ultimate parent same hai
        if(ulp_u == ulp_v) return;
        //jiska rank of ultimate parent chhota hai attach smaller one to larger one
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        //agar dono ka rank same hai then jisse attach kroge uska rank increase hoga
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        //dono ka ultimate parent same hai
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       DisjointSet ds(n);
       int extraEdges = 0;
       for(auto it : connections){
        int u = it[0];
        int v = it[1];
        //agar already connected hai ie ultimate parent same hai, matlab extra edge hai
        if(ds.findUParent(u) == ds.findUParent(v)){
            extraEdges++;
        }
        //agar connected ni h toh connect krdo
        else{
            ds.unionBySize(u, v);
        }
       }
       //total parents count krlo
       int components = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) components++;
        }
        //agar required number of edges(noOfParents-1) hai then return krdo 
       if(extraEdges >= components-1) return components-1;
        return -1;
    }
};
