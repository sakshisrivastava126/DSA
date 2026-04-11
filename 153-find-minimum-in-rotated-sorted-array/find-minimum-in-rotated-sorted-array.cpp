class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, h=arr.size()-1;
        int mini = INT_MAX;

        //the idea here is everytime we find a sorted half we will use the advantage and pick its lowest element as the minimum in that portion and then look for mini in the other half

        while(l <= h){
            int mid = l + (h-l)/2;

            //if left part is sorted, store the new minimum
            if(arr[l] <= arr[mid]){
                mini = min(mini, arr[l]);
                l = mid+1;
            }
            //if the right part is sorted, store the new minimum
            else{
                mini = min(mini, arr[mid]);
                h = mid-1;
            }
            
        }
        return mini;
    }
};