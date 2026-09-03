class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]%2 == 0){
            bool flag = true;
            for(auto it : nums){
                if(it%2 != 0) flag = false;
            }
            return flag;
        }
        else{
            return true;
        }
    }
};