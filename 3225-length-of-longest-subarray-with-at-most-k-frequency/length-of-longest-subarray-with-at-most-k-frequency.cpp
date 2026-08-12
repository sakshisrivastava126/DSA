class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        unordered_map<int, int> f;
        int ans = 0;

        while(r<n && l<=r){
            f[nums[r]]++;
            if(f[nums[r]] <= k){
                ans = max(ans, r-l+1);
            }
            else{
                while(f[nums[r]] > k){
                    f[nums[l]]--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};