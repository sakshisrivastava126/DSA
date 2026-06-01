class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int ans=0;
        if(n < 3){
            for(int i=0; i<n; i++){
                ans += cost[i];
            }
        }
        else{
            int i=n-1;
            for(i=n-1; i>=2; i-=3){
                ans += cost[i] + cost[i-1];
            }
            
            if(i >= 0){
                while(i >= 0){
                    ans += cost[i];
                    i--;
                }
            }
        }
        return ans;
    }
};