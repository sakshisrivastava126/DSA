class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a=0, b=0;
        int i=0, j=piles.size()-1;
        while(i < j){
            if(piles[i]>=piles[j]){
                a += piles[i];
                b += piles[j];
                i++;
                j--;
            }
            else{
                a += piles[j];
                b += piles[i];
                j--;
                i++;
            }
        }
        
        return a>=b;
    }
};