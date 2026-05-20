class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int> st;
        vector<int> v;
        for(int i=0; i<n; i++){
            st.insert(A[i]);
            int cur=0;
            for(int j=0; j<=i; j++){
                if(st.find(B[j]) != st.end()){
                    cur++;
                }
            }
            v.push_back(cur);
        }
        return v;
    }
};