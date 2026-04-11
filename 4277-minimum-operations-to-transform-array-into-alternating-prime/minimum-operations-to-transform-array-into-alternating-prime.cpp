class Solution {
public:
    bool check(int n){
        if(n <= 1) return false;
        for(int i=2; i*i <= n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int ans=0;
        
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                while(!check(nums[i])){
                    nums[i]++;
                    ans++;
                }
            }
            else{
                while(check(nums[i])){
                    nums[i]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};