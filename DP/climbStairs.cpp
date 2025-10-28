class Solution {
public:
    int climbStairs(int n) {
        //base cases : nothing to climb, in 1 way 
        //only 1 step to climb, in 1 way
        if(n<=1) return 1;
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
