class Solution {
public:
    int smallestNumber(int n, int t) {
        int sum = 0;
        for(int i=n; i<=n+10; i++){
            int prod=1;
            int j=i;
            while(j>0){
                int rem = j%10;
                prod *= rem;
                j = j/10;
            }
            if(prod%t ==0) return i;
        }
        return 0;
    }
};