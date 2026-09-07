class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int ans=0;
        unordered_map<char, int> mp;

        while(r < s.size()){
            mp[s[r]]++;

            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};