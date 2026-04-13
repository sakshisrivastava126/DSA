class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size();
        int n = mat[0].size();

        int row = 0, col = n-1;
        while(row < m && col >= 0){
            if(mat[row][col] == tar) return true;

            if(mat[row][col] < tar) row++;
            else col--;
        }
        return false;
    }
};