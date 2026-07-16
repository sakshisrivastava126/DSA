class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        vector<int> pg(n);

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            pg[i] = gcd(maxi, nums[i]);
            // cout << pg[i] << " ";
        }
        // cout << endl;
        sort(pg.begin(), pg.end());
        int l=0, r=n-1;
        long long sum=0;
        
        while(l < r){
            int curr = gcd(pg[l], pg[r]);
            // cout << curr << " ";
            sum += curr;
            l++;
            r--;
        }
        return sum;
    }
};