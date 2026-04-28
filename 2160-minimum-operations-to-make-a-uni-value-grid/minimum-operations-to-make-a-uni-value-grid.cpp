class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0;
        vector<int> v;
        
        for(auto it : grid){
            for(auto i : it){
                v.push_back(i);
            }
        }
        int rem = v[0]%x;
        for(int it : v){
            if(it%x != rem) return -1;
        }
        sort(v.begin(), v.end());
        int mid = v[v.size()/2];
        
        for(auto it : v){
            ans += abs(it-mid)/x;
        }
        return ans;
    }
};