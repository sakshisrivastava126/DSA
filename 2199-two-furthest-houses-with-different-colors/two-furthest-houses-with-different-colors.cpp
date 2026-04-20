class Solution {
public:
    int maxDistance(vector<int>& c) {
        int maxi = 0;
        int n = c.size();
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                if(c[i] != c[j]){
                    maxi = max(maxi, abs(i-j));
                }
            }
        }
        return maxi;
    }
};