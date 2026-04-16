class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int maxi = INT_MIN;
        int nse = 0, pse=0;
        stack<int> st; //indx

        for(int i=0; i<n; i++){
            int area = 0;
            while(!st.empty() && h[st.top()] > h[i]){
                int idx = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, h[idx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            int idx = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, h[idx]*(nse-pse-1));
        }
        return maxi;
    }
};