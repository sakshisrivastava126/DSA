class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int ans=0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]]++;
                ans = max(ans, r-l+1);
                r++;
            }
            else{
                while(mp.find(s[r]) != mp.end()){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};