class Solution {
public:
    bool solve(vector<int>& pos, int ans, int m){
        m-=1;
        int prev = pos[0];
        for(int i=1; i<pos.size(); i++){
            if(prev+ans <= pos[i]){
                m--;
                prev = pos[i];
                if(m==0) break;
            }
        }

        return m==0;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int h = pos[pos.size()-1];
        int l= 1;
        int ans=0;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(solve(pos, mid, m)){
                ans = max(ans, mid);
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};