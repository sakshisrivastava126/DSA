class Solution {
public:
    int minimumPushes(string word) {
        set<char> st;
        map<char, int> f, mp;
        for(auto ch : word){
            f[ch]++;
        }
        vector<pair<int, char>> v;
        for(auto [k, val] : f){
            v.push_back({val, k});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        int i=0; int ans=0; int push=1, cnt=0;
        while(i < v.size()){
            if(mp.find(v[i].second) == mp.end()){
                mp[v[i].second] = push;
                cnt++;
            }
            if(cnt == 8){
                push++;
                cnt=0;
            }
            i++;
        }
        for(char ch : word){
            if(!st.contains(ch)){
                int temp = f[ch] * mp[ch];
                ans += temp;
                st.insert(ch);
            }
        }
        return ans;
    }
};