class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int l = 0, h = n-1;
        while(l <= h){
            int mid = l +(h-l)/2;
            int row = 0;
            for(int i = 0; i < m; i++){
                if(mat[i][mid] > mat[row][mid]){
                    row = i;
                }
            }
            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 < n ? mat[row][mid+1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < left) h = mid-1;
            else l = mid+1;
        }
        return {-1, -1};
    }
};