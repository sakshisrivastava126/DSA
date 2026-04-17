class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(); int ans=INT_MAX;
        unordered_map<int, int> mp;
        
        for(int i=n-1; i>=0; i--){
            
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int it = stoi(s);

            if(mp.find(it) != mp.end() && i != mp[it]){
                ans = min(ans, abs(i - mp[it]));
            }
            mp[nums[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
