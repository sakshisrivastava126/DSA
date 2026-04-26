class Solution {
public:
    static bool comp(pair<int, char> &a, pair<int, char> &b){
            if(a.first != b.first){
                return a.first > b.first;
            }
        return a.second < b.second;
    }
    string sortVowels(string s) {
        int n = s.size();
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        vector<pair<int, char>> fre;
        unordered_map<char, int> mp;
        unordered_map<char, int> pos;
        
        for(int i=0; i<n; i++){
            if(st.find(s[i]) != st.end()){
                mp[s[i]]++; 
            }
            if(pos.find(s[i]) == pos.end()){
                pos[s[i]] = i;
            }
        }
  
        for(auto [k, v] : mp){
            fre.push_back({v, k});
        }
        sort(fre.begin(), fre.end(), [&](const pair<int,char>& a, const pair<int,char>& b){
            if(a.first != b.first) return a.first > b.first;
            return pos[a.second] < pos[b.second];  
        });
        
        vector<int> idx;
        for(int i=0; i<n; i++){
            if(st.find(s[i]) != st.end()){
                idx.push_back(i);
            }
        }

        int id = 0;
        while(id < idx.size()){
            
            for(int i=0; i<fre.size(); i++){
                char ch = fre[i].second;
                int freq = fre[i].first;
                for(int j=0; j<freq && id < idx.size(); j++){
                    s[idx[id]] = ch;
                    id++;
                }
            }
        }
        return s;
    }
};