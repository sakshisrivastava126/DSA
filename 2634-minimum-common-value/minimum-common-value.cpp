class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        set<int> st;
        for(auto it : nums2) st.insert(it);
        for(auto it : nums1){
            if(st.find(it) != st.end()) return it;
        }
        return -1;
    }
};