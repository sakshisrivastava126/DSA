class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int cnt=0;

        int l=0, r=0;
        
        while(r<n-1){
            int maxi=0;
            for(int i=l; i<=r; i++){
                maxi = max(maxi, nums[i]+i);
            }
            l=r+1;
            r = maxi;
            cnt++;
        }
        return cnt;
    }
};