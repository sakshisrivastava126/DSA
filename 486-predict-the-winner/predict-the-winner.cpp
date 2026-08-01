class Solution {
public:
    int solve(vector<int>& nums, int p1, int p2){
        if(p1 == p2){
            return nums[p1];
        }

        int left = nums[p1] - solve(nums, p1+1, p2);
        int right = nums[p2] - solve(nums, p1, p2-1);

        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int ans = solve(nums, 0, nums.size()-1);
        return ans >= 0;
    }
};