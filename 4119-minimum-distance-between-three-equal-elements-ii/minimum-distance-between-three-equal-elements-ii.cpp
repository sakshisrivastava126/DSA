class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto [k, v] : mp){
            if(v.size() > 2){
                sort(v.begin(), v.end());
                for(int j=1; j<v.size()-1; j++){
                    mini = min(mini, abs(v[j]-v[j-1]) + abs(v[j+1]-v[j]) + abs(v[j-1]-v[j+1]));
                }
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};