class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;
        char ans = ' ';

        for(char ch : s){
            freq[ch]++;
        }
        for(char ch : t){
            freq[ch]--;

            if(freq[ch] < 0) {
                ans = ch;
            }
        }
        return ans;
    }
};
