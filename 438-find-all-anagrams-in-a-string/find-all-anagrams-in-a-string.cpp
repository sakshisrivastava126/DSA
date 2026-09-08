class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int n = s.size();
        vector<int> need(26, 0);
        vector<int> wind(26, 0);
        vector<int> ans;

        for(char ch : p){
            need[ch-'a']++;
        }

        for(int i=0; i<n; i++){
            wind[s[i]-'a']++;

            if(i >= k){
                wind[s[i-k]-'a']--;
            }

            if(wind==need){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};