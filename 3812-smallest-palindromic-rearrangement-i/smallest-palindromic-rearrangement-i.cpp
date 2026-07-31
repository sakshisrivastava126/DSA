class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        unordered_map<char, int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        string ans, temp="";
        for(int i=0; i<=s.size(); i++){
            if(mp[s[i]] > 1){
                temp += s[i];
                mp[s[i]] -= 2;
            }
        }
        for(auto [k, val] : mp){
            if(val == 1){
                temp += k;
            }
        }
        ans = temp;
        if(s.size()%2 != 0){
            temp.pop_back();
        }
        reverse(temp.begin(), temp.end());
        return ans+temp;
    }
};