class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int, int> mp;
        mp[2]=5, mp[5]=2, mp[6]=9, mp[9]=6;
        int cnt=0;
        for(int i=1; i<=n; i++){
            string s = to_string(i);
            string cs = s;
            if(s.size() == 1){
                if(mp.find(i) != mp.end()) cnt++;
            }
            else{
                for(auto& it : s){
                    int x = it - '0';
                    if(mp.find(x) != mp.end()){
                        it = '0' + mp[x];
                    }
                    else if(x != 0 && x != 1 && x != 8){
                        cs = ""; 
                        break;
                    }

                }
                if(!cs.empty() && s != cs) cnt++;
            }
        }
        return cnt;
    }
};