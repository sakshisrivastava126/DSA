class Solution {
public:
    long long sumAndMultiply(int n) {

        long long sum = 0;
        long long x = 0;
        long long place = 1;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                sum += d;
                x = d * place + x;
                place *= 10;
            }
            n /= 10;
        }

        return sum * x;
    }
};