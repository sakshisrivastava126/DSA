class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> t1, t2;
        int n = nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                t1.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                t2.push_back(nums[i]);
            }
            else cnt++;
        }
        while(cnt--){
            t1.push_back(pivot);
        }
        for(auto it : t2){
            t1.push_back(it);
        }
        return t1;
    }
};