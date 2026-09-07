class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int ans=0,  maxFreq=0;
        unordered_map<char, int> mp;

        while(r<s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            // if(mp.size() > 1){
                if(mp.size() == 1 || (r-l+1 - maxFreq <= k)){
                    ans = max(ans, r-l+1);
                }
                // else{
                    while((mp.size() > 1) && (r-l+1 - maxFreq > k)){
                        mp[s[l]]--;
                        if(mp[s[l]] == 0){
                            mp.erase(s[l]);
                        }
                        l++;
                    }
                // }
            // }
            r++;
        }
        return ans;
    }
};