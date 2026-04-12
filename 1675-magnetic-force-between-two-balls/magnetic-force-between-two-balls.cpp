class Solution {
public:
    bool check(vector<int>& pos, int mid, int m){
        int cnt=1;
        int prev = pos[0];
        for(int i=1; i<pos.size(); i++){
            int curr = pos[i];
            if(curr - prev >= mid){
                cnt++;
                prev = curr;
            }
            if(cnt == m) break;
        }
        return cnt==m;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        
        int l = 1;
        int h = pos[pos.size()-1] - pos[0];
        
        int ans = -1;

        while(l<=h){
            int mid = l + (h-l)/2;

            if(check(pos, mid, m)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};