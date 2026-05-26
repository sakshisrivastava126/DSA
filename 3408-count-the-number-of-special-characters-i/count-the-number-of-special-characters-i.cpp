class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> mp;
        for(auto i : word) mp[i]++;
        int cnt=0;
        for(auto it : word){
            if(it >= 'a' && it <= 'z'){
                char ch = toupper(it);
                if(mp.find(ch) != mp.end()){
                    cnt++;
                    mp[ch]--;
                    mp.erase(ch);
                } 
            }
        }
        return cnt;
    }
};