class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        set<int> st;
        for(auto t : arr) st.insert(t);

        vector<int> v;
        for(int i=1; i<=10000; i++){
            if(st.find(i) == st.end()) v.push_back(i);
        }

        if(v.size()-1 >= k)
            return v[k-1];
        return -1;
    }
};