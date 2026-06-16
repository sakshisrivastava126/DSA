class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char ch : s){
            if(ch == '*'){
                if (!res.empty()) res.pop_back();
            }
            else if(ch == '#'){
                string temp = res;
                res += temp;
            }
            else if(ch == '%'){
                reverse(res.begin(), res.end());
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};