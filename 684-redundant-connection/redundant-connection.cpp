class Solution {
public:
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v];
        }
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet d(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int ulp_u = d.findUParent(u);
            int ulp_v = d.findUParent(v);
            if(ulp_u != ulp_v){
                d.unionBySize(u,v);
            }
            else{
                return {u, v};
            }
        }
        return {};
    }
};