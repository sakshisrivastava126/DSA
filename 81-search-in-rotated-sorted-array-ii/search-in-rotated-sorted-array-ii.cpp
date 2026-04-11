class Solution {
public:
    bool search(vector<int>& arr, int tar) {
        int l = 0, h = arr.size()-1;

        while(l <= h && h<arr.size()){
            int mid = l + (h-l)/2;
            if(arr[mid] == tar) return true;
            if(arr[l] == arr[mid] && arr[h] == arr[mid]){
                l++, h--;
                continue;
            }

            if(arr[l] <= arr[mid]){
                if(arr[l] <= tar && tar <= arr[mid]) h = mid-1;
                else l = mid+1;
            }
            else{
                if(arr[mid] <= tar && tar <= arr[h]) l = mid+1;
                else h = mid-1;
            }
        }
        return false;
    }
};