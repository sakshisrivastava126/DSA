class Solution {
public:
    vector<vector<string>> ans;
    vector<string> grid;
    void solve(int n, int col, vector<int>& row, vector<int>& ld, vector<int>& rd){
        if(col >= n){
            ans.push_back(grid);
            return;
        }
        for(int r=0; r<n; r++){
            if(row[r] == 0 && ld[r+col] == 0 && rd[n-1+col-r] == 0){
                row[r]=1;
                ld[r+col]=1;
                rd[n-1+col-r]=1;
                grid[r][col] = 'Q';

                solve(n, col+1, row, ld, rd);

                row[r]=0;
                ld[r+col]=0;
                rd[n-1+col-r]=0;
                grid[r][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        for(int i=0; i<n; i++){
            grid.push_back(s);
        }
        vector<int> row(n, 0);
        vector<int> ld(2*n-1, 0);
        vector<int> rd(2*n-1, 0);
        vector<string> curr(n);
        solve(n, 0, row, ld, rd);
        return ans;
    }
};