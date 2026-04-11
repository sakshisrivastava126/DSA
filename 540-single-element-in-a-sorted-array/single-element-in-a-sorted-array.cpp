class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        //edge cases:
        //if there is only one element in the array that is the ans
        if(n==1) return arr[0];
        //if we are on the left end and next element is not same 
        if(arr[0] != arr[1]) return arr[0];
        //if we are on the right end and prev element is not same 
        if(arr[n-2] != arr[n-1]) return arr[n-1];

        int l = 1, h = n-2;

        //the idea to move left or right is 
        // if we are on even and next element is same then we are on the left side of the element and element is actually on the right
        //ans if we are on odd and next element is even then vice-versa
        while(l <= h){
            int mid = l + (h-l)/2;
            //if next or prev none is same then that is the ans
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
                return arr[mid];
            }

            //if we at even and next isn't same or we are at odd and prev isn't same then we are on left side, find element on its right
            if((mid%2 == 0 && arr[mid] == arr[mid+1]) || (mid%2 != 0 && arr[mid] == arr[mid-1])){
                l = mid+1;
            }
            //we are on right side find element on the left
            else {
                h = mid-1;
            }
        }
        return -1;
    }
};