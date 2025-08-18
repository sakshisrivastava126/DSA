class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;
        int n = num.size();
        //edge case 
        if(k == n) return "0";

        st.push(num[0]);
        for(int i=1; i<n; i++){
            //remove elem form top till we find a smaller one on stack
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //edge case if remove hi ni hue K elems them remove krdo khud from top of stack
        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        ans.erase(0, ans.find_first_not_of('0'));
        if (ans.empty()) ans = "0";
        return ans;
    }
};
