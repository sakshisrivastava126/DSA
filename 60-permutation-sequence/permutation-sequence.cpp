class Solution {
public:
    string getPermutation(int n, int k) {
        int size = 1; //factorial
        vector<int> v;
        for(int i=1; i<n; i++){
            size *= i;
            v.push_back(i);
        }
        v.push_back(n);

        k-=1;
        string ans = "";

        while(true){
            int idx = k/size;
            ans += to_string(v[idx]);
            v.erase(v.begin() + idx);

            if(ans.size() == n) break;

            k = k%size;
            size = size/v.size();
        }
        return ans;
    }
};