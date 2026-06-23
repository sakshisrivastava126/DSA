class Solution {
public:
    bool check(vector<int>& quant, int mid, int n){
        int cnt=0;
        for(auto it : quant){
            cnt += it/mid;
            if(it%mid) cnt++;
            if(cnt > n) return false;
        }
        return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& quant) {
        sort(quant.begin(), quant.end());
        int sz = quant.size();
        int l=1, h=100000;
        int ans = -1;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(check(quant, mid, n)){
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