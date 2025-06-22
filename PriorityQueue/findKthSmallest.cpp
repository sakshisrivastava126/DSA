#include <queue>
class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        int i = k-1;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }

        while(n >= 0 && i>0){
            pq.pop();
            i--;
        }

        int res = pq.top();
        return res;
    }
};
