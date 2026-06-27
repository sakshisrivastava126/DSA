class Solution {
public:
    bool check(int& mid, int& k, int m, int n){
        int cnt=0;
        for(int i=1; i<=m; i++){
            cnt += min(n, mid/i);
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) {
      
        int l = 1;
        int r = m*n;
        int ans=0; 

        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(mid, k, m, n)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};