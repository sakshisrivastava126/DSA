class Solution {
public:
    bool rotateString(string s, string goal) {
        string p = s;
        p += s;
        if(s.size() != goal.size()) return 0;
        int n = s.size();
        for(int i=0; i<2*n-n; i++){
            string ns = p.substr(i, n);
            if(ns == goal) return true;
        }
        return false;
    }
};