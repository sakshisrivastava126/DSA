class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //sari values set me daal di
       set<int> s(nums.begin(), nums.end());
       int maxi=0;

        //traverse through array and check kya prev seq element exist krta hai iss element ka?
       for(int elem : s){
        int cnt=0;
        //agar ni krta then it is start of a sequence, check krlo further 
            if(s.find(elem-1) == s.end()){
                while(s.find(elem) != s.end()){
                    cnt++;
                    elem++;
                }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
