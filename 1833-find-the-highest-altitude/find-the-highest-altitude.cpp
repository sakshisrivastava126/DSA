class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans=0, alt=0;
        for(auto it : gain){
            alt = alt + it;
            ans = max(ans, alt);
        }
        return ans;
    }
};