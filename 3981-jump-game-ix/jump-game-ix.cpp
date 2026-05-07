class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), smal(n), lar(n);
        
        int maxi = *max_element(nums.begin(), nums.end());
        lar[0] = nums[0];
        for(int i=0; i<n; i++){
            lar[i] = (i == 0 ? nums[i] : max(lar[i-1], nums[i]));
        }

        smal[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            smal[i] = min(smal[i+1], nums[i]);
        }
        ans[n-1] = maxi;
        for(int i=n-2; i>=0; i--){
            if(lar[i] > smal[i+1]){
                ans[i] = ans[i+1];
            }
            else ans[i] = lar[i];
        }

        return ans;
    }
};