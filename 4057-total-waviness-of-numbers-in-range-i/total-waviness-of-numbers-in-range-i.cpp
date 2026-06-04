class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int sum=0;
        for(int n=num1; n<=num2; n++){
            int cnt1 = 0;
            string n1 = to_string(n);
            if(n1.size() <3) continue;
            for(int i=1; i<n1.size()-1; i++){
                if((n1[i-1] - '0') < (n1[i] - '0') && (n1[i] - '0') > (n1[i+1] - '0')) cnt1++;
                else if((n1[i-1] - '0') > (n1[i] - '0') && (n1[i] - '0') < (n1[i+1] - '0')) cnt1++;
            }
            sum += cnt1;
        }
        
        return sum;
    }
};