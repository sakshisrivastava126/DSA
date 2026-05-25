class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if(s[n-1] == '1') return false;

        vector<int> pre(n+1, 0);
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += pre[i];

            if(i == 0 || (sum && s[i] == '0')){
                int l = min(i+minJump, n);
                int r = min(i+maxJump+1, n);
                pre[l]++;
                pre[r]--;
            }
        }
        return (sum > 0);
    }
};