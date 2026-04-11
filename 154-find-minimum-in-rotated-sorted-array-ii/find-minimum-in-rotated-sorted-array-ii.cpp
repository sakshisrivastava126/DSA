class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, h = arr.size()-1; //l = low and h = high
        int mini = INT_MAX;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(arr[l] == arr[mid] && arr[mid] == arr[h]){
                mini = min(mini, arr[l]);
                l++, h--;
                continue;
            }

            if(arr[l] <= arr[mid]){
                mini = min(mini, arr[l]);
                l = mid+1;
            }
            else{
                mini = min(mini, arr[mid]);
                h = mid-1;
            }
        }
        return mini;
    }
};