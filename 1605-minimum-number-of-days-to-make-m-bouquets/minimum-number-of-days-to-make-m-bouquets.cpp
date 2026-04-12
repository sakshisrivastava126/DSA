class Solution {
public:
    bool canUse(vector<int>& bd, int day, int k, int m){
        int curr=0;
        int cnt=0;
        for(int i=0; i<bd.size(); i++){
            if(bd[i] <= day){
                curr++;
                if(curr==k) {
                    cnt++;
                    curr=0;
                }
            } 
            else curr=0;
        }
        if(cnt >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        // long long mul = m*k;
        // if(mul > bloomDay.size()) return -1;

        int l = 1, h = maxi;
        int ans = -1;

        while(l <= h){
            int mid = l + (h-l)/2;
            cout << mid << " ";

            if(canUse(bloomDay, mid, k, m)){
                // cout << "called" << " ";
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