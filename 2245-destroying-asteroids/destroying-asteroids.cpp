class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        long long curr = (int)mass;
        for(auto it : a){
            if(curr < it) return false;
            else curr += it;
        }
        return true;
    }
};