class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = 0; int ans=0;
        for(int i=1; i<p.size(); i++){
            if(p[mini] <= p[i]){
                ans = max(ans, p[i]-p[mini]);
            }
            else{
                mini = i;
            }
        }
        return ans;
    }
};