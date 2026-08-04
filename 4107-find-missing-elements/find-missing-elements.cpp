class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        set<int> st;
        for(auto it : nums) st.insert(it);
        vector<int> v;
        for(int i=mini; i<=maxi; i++){
            if(st.find(i) == st.end()) v.push_back(i);
        }
        return v;
    }
};