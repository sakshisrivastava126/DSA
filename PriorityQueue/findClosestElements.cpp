class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.empty()) return {};
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i=0; i<arr.size(); i++){
            pq.push({abs(x-arr[i]), arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
