class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto& it : s){
            if(it == '('){
                st.push('(');
            }
            else if(it == '{'){
                st.push('{');
            }
            else if(it == '['){
                st.push('[');
            }
            else{
                if(st.empty()) return false;
                if(it == ')' && st.top() == '(') st.pop();
                else if(it == ')' && st.top() != '(') return false;
                if(it == '}' && st.top() == '{') st.pop();
                else if(it == '}' && st.top() != '{') return false;
                if(it == ']' && st.top() == '[') st.pop();
                else if(it == ']' && st.top() != '[') return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};