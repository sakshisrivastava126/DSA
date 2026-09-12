class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = nums[i] + pre[i-1];
        }

        int ans=0;
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int l=0; l<n; l++){
            int rem = (pre[l]%k + k)%k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};