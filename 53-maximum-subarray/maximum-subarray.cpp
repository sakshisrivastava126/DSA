class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= -10e4+1, maxi= -10e4+1;
        for(auto it : nums){
            maxi = max(maxi+it, it);
            ans = max(ans, maxi);
        }
        return ans;
    }
};