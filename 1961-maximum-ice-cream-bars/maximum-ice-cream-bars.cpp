class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum=0;
        int i=0; int cnt=0;
        for(i=0; i<costs.size(); i++){
            sum += costs[i];
            if(sum > coins) break;
            cnt++;
        }
        // if(i==1) return 0;
        return cnt;
    }
};