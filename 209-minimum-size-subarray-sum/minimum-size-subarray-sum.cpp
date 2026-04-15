class Solution {
public:
    bool check(int t, vector<int>& v, int mid){
        vector<int> pre(v.size()+1);
        pre[0] = 0;
        pre[1] = v[0];
        for(int i=2; i<=v.size(); i++){
            pre[i] = pre[i-1]+v[i-1];
        }
        cout << endl;
        bool flag = false;
        for(int i=1; i<=v.size()-mid+1; i++){
            if(t <= pre[i+mid-1]- pre[i-1]){
                flag = true;
            } 
        }
        return flag;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int l = 0;
        int h = n;
        int ans=0;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(target, nums, mid)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};