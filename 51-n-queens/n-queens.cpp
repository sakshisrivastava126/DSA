class Solution {
public:
    vector<vector<string>> ans;
    void rec(int col, vector<int>& row, vector<int>& ld, vector<int>& rd, vector<string>& grid){
        int n = row.size();
        if(col >= row.size()) {
            ans.push_back(grid);
            return;
        }

        for(int i=0; i<row.size(); i++){
            if(row[i] == 0 && ld[i+col] == 0 && rd[n-1+col-i] == 0){
                
                grid[i][col] = 'Q';
                row[i] = 1;
                ld[i+col] = 1;
                rd[n-1+col-i] = 1;

                rec(col+1, row, ld, rd, grid);

                grid[i][col] = '.';
                row[i] = 0;
                ld[i+col] = 0;
                rd[n-1+col-i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid;
        string s(n, '.');
        for(int i=0; i<n; i++){
            grid.push_back(s);
        }
        vector<int> row(n, 0);
        vector<int> ld(2*n-1, 0);
        vector<int> rd(2*n-1, 0);
        rec(0, row, ld, rd, grid);
        return ans;
    }
};