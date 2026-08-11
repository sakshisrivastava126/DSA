class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int longest = nums[0];
        int n = nums.size();
        if(n==1) return nums[0]+1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1){
                longest += nums[i];
            }
            else{
                break;
            }
        }
        set<int> st;
        for(auto it : nums) st.insert(it);
        int i=0;
        while(st.find(longest) != st.end()){
            longest++;   
        }
        return longest;
    }
};