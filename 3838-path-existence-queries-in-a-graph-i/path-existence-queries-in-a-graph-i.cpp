class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> g(n, 0);
        int comp = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] > maxDiff){
                comp++;
            }
            g[i] = comp;
        }

        vector<bool> ans;
        for(auto& it : queries){
            int u = it[0];
            int v = it[1];
            ans.push_back(g[u]==g[v]);
        }
        return ans;
    }
};