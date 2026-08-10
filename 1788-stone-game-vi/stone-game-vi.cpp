class Solution {
public:
    int solve(vector<int>& av, vector<int>& bv, vector<pair<int, int>>& sum, int i, bool turn){
        if(i >= av.size()) return 0;
        int idx = sum[i].second;

        if(turn){
            return sum[i].first - bv[idx]+solve(av, bv, sum, i+1, !turn);
        }
        else{
            return solve(av, bv, sum, i+1, !turn) - (sum[i].first - av[idx]);
        }
    }
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        vector<pair<int, int>> sum;
        for(int i=0; i<av.size(); i++){
            sum.push_back({av[i]+bv[i], i});
        }
        sort(sum.begin(), sum.end(), [](pair<int, int> a, pair<int, int> b){
           return a.first > b.first;
        });
        int temp = solve(av, bv, sum, 0, 1);
        if(temp>0) return 1;
        else if(temp<0) return -1;
        else return 0;
    }
};