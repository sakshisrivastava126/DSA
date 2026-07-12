class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> ca;
        ca = arr;
        sort(ca.begin(), ca.end());
        int rnk = 1;
        int prev = -1e9;
        unordered_map<int, int> mp;
        for(int i=0; i<ca.size(); i++){
            if(prev != ca[i] && i != 0){
                rnk++;
            }
            mp[ca[i]] = rnk;
            prev = ca[i];
        }

        for(auto it : arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};