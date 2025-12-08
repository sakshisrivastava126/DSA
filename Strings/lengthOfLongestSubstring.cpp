class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hm;
        int l = 0;
        int maxLen = 0;

        for(int r=0; r< s.size(); r++){
            char ch = s[r];

            //agar map me ni h toh daaldo
            if(hm.find(ch) == hm.end()){
                hm.insert({ch, r});
            }

            //agar map me hai per hmare left pointer se pehle hai
            //yani hamne usse past me use kr rakha h 
            //so, update index of char
            else if(hm.find(ch) != hm.end() && hm[ch] < l){
                hm[ch] = r;
            }

            //map me bhi hai and substring me bhi hai
            //toh left pointer move krdo uske index se ek aage
            else{
                l = hm[ch] + 1;
                hm[ch] = r;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
