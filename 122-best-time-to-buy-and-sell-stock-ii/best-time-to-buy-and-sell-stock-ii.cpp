class Solution {
public:
    int maxProfit(vector<int>& p) {
        int pr=0;
        int mini = 0;
        for(int i=1; i<p.size(); i++){
            if(p[mini] <= p[i]){
                pr += p[i]-p[mini];
                mini = i;
            }
            else{
                mini = i;
            }
        }
        return pr;
    }
};