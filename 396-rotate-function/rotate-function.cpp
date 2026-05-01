class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        int mul = 0;
        int sum = 0;
        for(auto it : nums){
            sum += it;
            maxi += mul*it;
            mul++;
        }

        int curr = maxi;
        for(int i=0; i<n; i++){
            curr = curr - (n*nums[n-i-1]) + sum;
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};