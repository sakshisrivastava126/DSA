class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();

        vector<int> suff(n);
        int i=n-1, j=m-1; int match=0;
        while(i>=0){
            if(j>=0 && w1[i] == w2[j]){
                match++;
                j--;
            }
            suff[i] = match;
            i--;
        }

        vector<int> ans;
        bool allow = true; i=0, j=0;
        while(i<n && j<m){
            if(w1[i] == w2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if(allow && i+1 < n && suff[i+1] >= m-1-j){
                    ans.push_back(i);
                    j++;
                    allow = false;
                }
            }
            i++;
        }
        if(ans.size() == m) return ans;
        else return {};
    }
};