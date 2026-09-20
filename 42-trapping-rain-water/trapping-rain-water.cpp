class Solution {
public:
    int trap(vector<int>& h) {
        int water=0;
        int n = h.size();
        int l=0, r=n-1;
        int lmax = h[0], rmax = h[n-1];

        while(l < r){
            if(lmax < rmax){
                water += lmax-h[l];
                l++;
                lmax = max(lmax, h[l]);
            }
            else{
                water += rmax - h[r];
                r--;
                rmax = max(rmax, h[r]);
            }
        }
        return water;
    }
};