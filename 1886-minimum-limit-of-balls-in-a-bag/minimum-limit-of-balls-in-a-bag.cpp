class Solution {
public:
    bool check(vector<int>& nums, int mid, int maxOp){
        int cnt=0;
        for(auto it : nums){
            if(it%mid == 0) cnt += it/mid - 1;
            else if(it > mid) cnt += it/mid;
            if(cnt > maxOp) return 0;
        }
        return cnt<=maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOp) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, h = nums[n-1];
        int ans = -1;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(nums, mid, maxOp)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};