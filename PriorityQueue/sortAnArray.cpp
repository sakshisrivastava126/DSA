class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minH;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            minH.push(nums[i]);
        }
        nums.clear();
        while(!minH.empty()){
            int num = minH.top();
            minH.pop();
            nums.push_back(num);
        }
        return nums;
    }
};
