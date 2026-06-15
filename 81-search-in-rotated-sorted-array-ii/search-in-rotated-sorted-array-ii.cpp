class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int l=0, h= nums.size()-1;

        while(l <=h ){
            int mid = (h+l)/2;
            if(tar == nums[mid]) return true;

            if(nums[mid] == nums[l] && nums[mid]==nums[h]){
                l++, h--;
                continue;
            }

            if(nums[l] <= nums[mid]){
                if(nums[l] <= tar && tar <= nums[mid]) h = mid-1;
                else l = mid+1; 
            }
            else{
                if(nums[mid] <= tar && tar <= nums[h]) l=mid+1;
                else h = mid-1;
            }
        }
        return false;
    }
};