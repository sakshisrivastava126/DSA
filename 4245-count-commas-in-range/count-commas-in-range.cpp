class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        if(s.size() <= 3) return 0;
        int ans=0;
            ans = n-1000+1;
        return ans;
    }
};