class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(auto it : piles){
            maxi = max(maxi, it);
        }
        int l = 1, r = maxi;
        int ans = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;

            long reqTime = 0;
            for(int i=0; i<piles.size(); i++){
                reqTime += (piles[i] + mid - 1) / mid;
            }
            if(reqTime <= h){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};
