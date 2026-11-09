class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty()) return ans;

        sort(strs.begin(), strs.end());
        string front = strs[0];
        string back = strs[strs.size()-1];

        for(int i=0; i<min(front.size(), back.size()); i++){
            if(front[i] != back[i]){
                return ans;
            }
            ans += front[i];
        }
        return ans;
    }
};