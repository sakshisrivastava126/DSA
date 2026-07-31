class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        unordered_map<char, int> mp;
        int i=0; int push=1, cnt=0;
        while(i < word.size()){
            if(mp.find(word[i]) == mp.end()){
                mp[word[i]] = push;
                cnt++;
            }
            if(cnt == 8){
                push++;
                cnt=0;
            }
            i++;
        }
        for(auto ch : word){
            ans += mp[ch];
        }
        return ans;
    }
};