class Solution {
public:
    bool check(vector<int>& nums, int mid, int k){
        int parts=0;
        int curr=0;
        for(auto it : nums){
            if(curr + it <= mid){
                curr += it;
            }
            else{
                parts++;
                curr = it;
            }
        }
        return parts+1 <=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int sum=0;
        for(auto it : nums) sum += it;

        int l= *max_element(nums.begin(), nums.end()), h=sum;
        int ans=0;
        
        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(nums, mid, k)){
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