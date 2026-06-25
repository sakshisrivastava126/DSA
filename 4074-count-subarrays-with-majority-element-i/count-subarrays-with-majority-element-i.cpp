class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0, n = nums.size();
        for(int i=0; i<n; i++){
            unordered_map<int, int> mp;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                
                int sz = j - i + 1;
                if(mp[target]*2 > sz) ans++;
            }
        }
        return ans;
    }
};