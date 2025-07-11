class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty()) return {{}};
        vector<vector<int>> ans;
        //sum, index of nums1, index of nums1
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minH;

        int n = min((int)nums1.size(), k);
        for(int i=0; i<n; i++){
            minH.emplace(nums1[i]+nums2[0], i, 0);
        }

        while(!minH.empty() && ans.size()<k){
            auto[sum, i, j] = minH.top();
            minH.pop();
            ans.push_back({nums1[i], nums2[j]});

            if(j+1 < nums2.size()){
                minH.emplace(nums1[i]+nums2[j+1], i, j+1);
            }
        }
        return ans;
    }
};
