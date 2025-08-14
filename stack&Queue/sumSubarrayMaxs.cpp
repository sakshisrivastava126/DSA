class Solution {
private:
    //next smaller element
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }
        return ans;
    }  
    //prev smaller or equal element
    vector<int> findPSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }  
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse;
        vector<int> psee;

        nse = findNSE(arr);
        psee = findPSEE(arr);

        long long total = 0;

        for(int i=0; i<arr.size(); i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + left * right * arr[i]);
        }
        return total;
    }
    //next larger element
    vector<int> findNLE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }
        return ans;
    }  
    //prev larger or equal element
    vector<int> findPLEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nle = findNLE(arr);       
        vector<int> plee = findPLEE(arr);

        long long total = 0;

        for(int i=0; i<arr.size(); i++){
            long long left = i - plee[i];
            long long right = nle[i] - i;

            total = (total + left * right * arr[i]);
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
    long long maxSum = sumSubarrayMaxs(nums);
    long long minSum = sumSubarrayMins(nums);

    return maxSum - minSum ;
    }
};
