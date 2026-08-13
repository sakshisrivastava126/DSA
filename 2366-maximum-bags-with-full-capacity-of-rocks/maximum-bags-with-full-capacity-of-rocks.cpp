class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int n = rocks.size();
        vector<pair<int,int>> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = {capacity[i]-rocks[i], i};
        }
        sort(diff.begin(), diff.end(), [](auto a, auto b){
            return a.first < b.first;
        });

        int ans=0; int i=0;
        while(ar > 0 && i<n && ar >= diff[i].first){
            ar -= diff[i].first;
            ans++; i++;
        }
        return ans;
    }
};