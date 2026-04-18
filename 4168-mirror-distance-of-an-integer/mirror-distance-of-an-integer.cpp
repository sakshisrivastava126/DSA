class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        string s = to_string(temp);
        reverse(s.begin(), s.end());
        temp = stoi(s);
        return abs(n-temp);
    }
};