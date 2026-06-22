class Solution {
public:
    int rearrangeCharacters(string text, string target) {
        unordered_map<char, int> mp;
        for(auto ch : text){
            mp[ch]++;
        }
        int ans=0;
        bool flag= false;
        string b = target;
        while(true){
            for(auto it : b){
                mp[it]--;
                if(mp[it] < 0){
                    flag = true;
                    break;
                } 
            }
            ans++;
            if(flag) break;
        }
        return ans-1;
    }
};