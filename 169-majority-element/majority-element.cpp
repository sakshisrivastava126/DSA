class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=0;
        int cnt=1, elem=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==elem){
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