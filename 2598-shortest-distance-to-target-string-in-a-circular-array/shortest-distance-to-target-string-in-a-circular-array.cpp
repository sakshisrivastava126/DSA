class Solution {
public:
    int closestTarget(vector<string>& words, string target, int si) {
        int n = words.size();
        int dis = INT_MAX;

        for(int i=0; i<n; i++){
            if(words[i] == target){
                int prev = (i -si + n) % n;
                // int prev = abs(((i+n-1)%n) - si);
                int next = (si -i + n) % n;;
                // cout << prev << " " << next << endl;
                dis = min({dis, prev, next});
            }
        }
        return dis == INT_MAX ? -1 : dis;
    }
};