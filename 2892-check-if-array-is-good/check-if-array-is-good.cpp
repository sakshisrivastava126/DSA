class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> f;
        for(auto it : nums){
            f[it]++;
        }
        if(n != maxi+1) return false;
        if(f[maxi] != 2) return false;
        for(int i=1; i<=maxi; i++){
            if(f.find(i) == f.end()) return false;
        }
        return true;
    }
};