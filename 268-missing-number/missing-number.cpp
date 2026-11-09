class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int exp = n*(n+1)/2;
        int act=0;
        for(auto it : nums) act += it;
        return exp-act;
    }
};