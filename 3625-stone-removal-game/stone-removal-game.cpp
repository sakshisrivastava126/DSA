class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool turn = true;

        while(n>0){
            n -= remove;
            remove--;
            turn = !turn;
        }
        if(n==0) return !turn;
        return turn;
    }
};