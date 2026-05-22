class Solution {
public:
    void possiblePrefixes(unordered_set<string> &st, vector<int>& v){
        for(auto it : v){
            string s = to_string(it);
            string curr = "";
            for(auto i : s){
                curr += i;
                st.insert(curr);
            }
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int maxi=0;
        unordered_set<string> st;
        if(n < m){
            possiblePrefixes(st, arr1);
            for(auto it : arr2){
                string s = to_string(it);
                string curr = "";
                for(auto i : s){
                    curr += i;
                    if(st.find(curr) != st.end()){
                        int x = curr.size();
                        maxi = max(maxi, x);
                    }
                }
            }
        }
        else{
            possiblePrefixes(st, arr2);
            for(auto it : arr1){
                string s = to_string(it);
                string curr = "";
                for(auto i : s){
                    curr += i;
                    if(st.count(curr)){
                        int x = curr.size();
                        maxi = max(maxi, x);
                    }
                }
            }
        } 

        return maxi;
    }
};