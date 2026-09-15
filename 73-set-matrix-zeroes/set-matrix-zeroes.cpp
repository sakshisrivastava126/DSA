class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        set<int> r, c;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(r.count(i)){
                    mat[i][j]=0;
                }
                else if(c.count(j)){
                    mat[i][j]=0;
                }
            }
        }
        
    }
};