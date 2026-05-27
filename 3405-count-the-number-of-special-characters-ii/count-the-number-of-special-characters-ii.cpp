class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> mp;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z'){
                mp[word[i]] = i;
            }
            else{
                if(mp.find(word[i]) == mp.end()){
                    mp[word[i]] = i;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<word.size(); i++){
            int it = word[i];
            if(it >= 'a' && it <= 'z'){
                char ch = toupper(it);
                if(mp.find(ch) != mp.end()){
                    int idx = mp[ch];
                    mp.erase(ch);
                    if(idx > mp[word[i]]) cnt++;
                }
            }
        }
        return cnt;
    }
};