class Solution {
public:
    int solve(string& s, int l, int r, int k){
        if(r-l+1 < k) return 0;

        unordered_map<char, int> f;
        for(int i=l; i<=r; i++) f[s[i]]++;

        for(int i=l; i<=r; i++){
            if(f[s[i]] < k){
                int left = solve(s, l, i-1, k);
                int ryt = solve(s, i+1, r, k);

                return max(left, ryt);
            }
        }
        return r-l+1;
    }
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size()-1, k);
    }
};