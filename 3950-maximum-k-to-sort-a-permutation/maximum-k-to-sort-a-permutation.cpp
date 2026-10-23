class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int k=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != v[i]){
                k = nums[i] & k;
            }
        }
        return k == -1 ? 0 : k;
    }
};