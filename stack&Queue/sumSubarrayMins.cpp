class Solution {
private:
    //next smaller element
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        //we are storing index in the stack 
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            //if there is no next smaller elem, then number of subarrays we can generate will go till the size of the original array
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
            //we will also store equal index, we wont pop it to avoid edge case
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }  
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse;
        vector<int> psee;

        nse = findNSE(arr);
        psee = findPSEE(arr);

        long long total = 0;
        long long mod=1e9+7;

        for(int i=0; i<arr.size(); i++){
            //check left me kitne valid startings ho skti subarray ki
            //and kitne right me kitni valid endings ho sakti subarray ki for each element
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (right*left*arr[i]*1LL))%mod;
        }
        return (int)total;
    }
};
