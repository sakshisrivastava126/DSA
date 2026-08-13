class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        int prev = nums[n-1];

        for(int i=n-2; i>=0; i--){
            if(prev < nums[i]){
                int parts = nums[i]/prev;
                if(nums[i]%prev != 0) parts++;
                ans += parts-1;
                prev = nums[i]/parts;
            }
            else{
                prev = nums[i];
            }
        }
        return ans;
    }
};