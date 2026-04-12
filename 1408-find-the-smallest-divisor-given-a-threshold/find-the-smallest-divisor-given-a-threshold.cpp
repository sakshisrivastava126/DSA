class Solution {
public:
    bool check(vector<int>& nums, int t, int mid){
        int curr = 0;
        for(auto it : nums){
            curr +=  (it + mid-1)/mid;
        }
        if(curr <= t) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int maxi = *max_element(nums.begin(), nums.end());
        int l = 1, h = maxi;
        int ans = -1;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(nums, t, mid)){
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