class Solution {
public:
    bool check(vector<int>& w, int mid, int d){
        int i=0; 
        int temp = mid;
        int days = 1;
        
        while(i < w.size()){
            temp -= w[i];
            if(temp < 0){
                temp = mid - w[i];
                days++;
            }
            i++;
        }

        if(days <= d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int tw = 0;
        for(auto it : weights){
            tw += it;
        }
        int l = *max_element(weights.begin(), weights.end());
        int h = tw;
        int ans = -1;

        while(l <= h){
            int mid = l + (h-l)/2;
            cout << mid << " ";

            if(check(weights, mid, days)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};