class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            columnNumber--;
            int r = columnNumber%26;
            ans = char('A' + r) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};
