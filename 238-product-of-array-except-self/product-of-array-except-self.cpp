class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n, 1);
        pre[0] = 1;
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        int suff=1;
        for(int i=n-2; i>=0; i--){
            suff = suff*nums[i+1];
            ans[i] = suff*pre[i];
        }
        ans[n-1] = pre[n-1];
        return ans;
    }
};