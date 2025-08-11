class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);

//idea is to use a new array(double the size of original with same elements) and find next greatest 
        for(int i= 2*n - 1; i>=0; i--){
            int indx = i%n;

            while(!st.empty() && st.top() <= nums[indx]){
                st.pop();
            }

            if(i < n){
                ans[indx] = st.empty() ? -1 : st.top();
            }
            st.push(nums[indx]);
        }
        return ans;
    }
};
