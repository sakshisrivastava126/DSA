class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int cnt=0;
        int prev = nums[0];
        vector<int> org;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                org.push_back(1);
            }
            else if(nums[i] == nums[i-1]){
                org.push_back(0);
            }
            else{
                org.push_back(-1);
            }
        }
        
        int j=0;
        int i=0;
        while(i<org.size()){
            int idx = i;
            j=0;
            while(idx < org.size() && j < pattern.size() && org[idx] == pattern[j]){
                j++;
                idx++;
            }
            if(j == pattern.size()){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};