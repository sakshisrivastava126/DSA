class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<char> st;
        st.push('*');
        int i = 0;
        
        while(i < s.size()){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    cnt++;
                }
            }
            i++;
        }
        while(st.top() != '*'){
            st.pop();
            cnt++;
        }
        return cnt;
    }
};