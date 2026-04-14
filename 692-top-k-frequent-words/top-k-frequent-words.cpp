class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first; 
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }

        for(auto [s, cnt] : mp){
            pq.push({cnt, s});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            int cnt = pq.top().first;
            string s = pq.top().second;
            pq.pop();

            ans.push_back(s);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};