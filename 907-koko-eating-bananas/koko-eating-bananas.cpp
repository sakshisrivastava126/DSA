class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(auto it : piles){
            maxi = max(maxi, it);
        }
        
        int l=1, r=maxi+1;
        int ans=INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            
            long long curr=0;
            for(auto it : piles){
                if(it <= mid) curr += 1;
                else{
                    if(it%mid == 0) curr += it/mid;
                    else curr += (it/mid) +1;
                } 
            }
            if(curr <= h){
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