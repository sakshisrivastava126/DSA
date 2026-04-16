class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto q : queries){
            int curr = INT_MAX;
            auto& v = mp[nums[q]];

            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int x = v.size();

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int nxt = (pos+1)%x;
            if(v[nxt] != q){
                int d = (v[nxt] - q + n)%n;
                curr = min(curr, d);
            }
            
            int prev = (pos-1 +x)%x;
            if(v[prev] != q){
                int d = (q - v[prev] + n)%n;
                curr = min(curr, d);
            }

            if(curr == INT_MAX) curr = -1;
            ans.push_back(curr);
        }
        return ans;
    }
};