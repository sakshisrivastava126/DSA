class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for(string word : words){
            int w = 0;
            int currChar = 0;
            for(auto ch : word){
               w += weights[ch - 'a'];
            }
            currChar = w%26;

            ans += char('a' + (25-currChar));
            
        }
        return ans;
    }
};