class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums){
            vector<int> curr;
            while(n>0){
                int rem = n%10;
                curr.push_back(rem);
                n = n/10;
            }
            for(int i=curr.size()-1; i>=0; i--){
                ans.push_back(curr[i]);
            }
        }
        return ans;
    }
};