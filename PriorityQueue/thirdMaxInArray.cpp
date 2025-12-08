class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s;
        priority_queue<int> pq;
        for(int i=0; i< nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
        }
        if(pq.size() < 3) return pq.top();

        else{
            pq.pop();
            pq.pop();
            return pq.top();
        }
    }
};
