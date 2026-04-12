class Solution {
public:
    bool check(vector<int>& arr, int k, int mid){
        int i=0; int cnt=1; int curr=0;

        for(int i = 0; i < arr.size(); i++){
            if(curr + arr[i] <= mid){
                curr += arr[i];
            } 
            else {
                cnt++;
                curr = arr[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums) total += it;

        int l = *max_element(nums.begin(), nums.end());
        int h = total;
        
        int ans = 0;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(nums, k, mid)){
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