class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inv) {
        sort(inv.begin(), inv.end());
        int n = inv.size();
        int cnt=0;

        for(int i=0; i<n; i++){
            int currBeg = inv[i][0];
            int currEnd = inv[i][1];
            bool flag = false;
            for(int j=0; j<n; j++){
                if(j == i) continue;
                if(currBeg >= inv[j][0] && currEnd <= inv[j][1]){
                    flag = true;
                }
            }
            if(!flag) cnt++;
        }

        return cnt;
    }
};