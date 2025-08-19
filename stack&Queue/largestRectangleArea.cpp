class Solution {     
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; //storing index of larger elem than those already present in stack
        int maxArea = 0;
        int n = heights.size();
        
        for(int i=0; i< n; i++){
            //popping out when: jo elem mila uski value kam ho stack me jo value hai usse
            while(!st.empty() && heights[st.top()]>heights[i]){
                //we are calculating area when we pop out from stack
                //so that we alse have nse for each elem
                int elem = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[elem]*(nse-pse -1), maxArea);
            }
            st.push(i);
        }
        //we traversed all but still have elem in stack so we'll calculate for them separately
        while(!st.empty()){
            int nse = n;
            int elem = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[elem]*(nse-pse -1), maxArea);
        }
        return maxArea;
    }
};
