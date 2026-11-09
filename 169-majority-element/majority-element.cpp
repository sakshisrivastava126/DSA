class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int n = nums.size();
        int elem = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == elem){
                cnt++;
            }
            else{
                if(cnt==0){
                    elem = nums[i];
                    cnt=1;
                }
                cnt--;
            }
        }
        return elem;
    }
};