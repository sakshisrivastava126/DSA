class Solution {
public:
    bool comp(string s, string tar){
        set<char> st;
        int cnt=0;
        if(s.size() != tar.size()) return false;

        for(int i=0; i<s.size(); i++){
            if(s[i] != tar[i]) cnt++;
        }
        
        if(cnt <= 2) return true;
        return false;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& dic) {
        vector<string> ans;

        for(int i=0; i<q.size(); i++){
            string s = q[i];

            for(auto tar : dic){
                if(comp(s, tar)){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }   
};