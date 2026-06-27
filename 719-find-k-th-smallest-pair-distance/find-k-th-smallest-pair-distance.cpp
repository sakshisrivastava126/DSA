class Solution {
public:
    bool check(vector<int>& nums, int k, int mid){
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]-nums[i] <= mid) cnt++;
                else break;
            }
        }
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int diff = nums[n-1] - nums[0];
        int ans=0;

        int l=0, h=diff;
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