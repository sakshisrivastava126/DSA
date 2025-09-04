class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));

        queue<pair<pair<int,int>, int>> q;  //row,col,distance

        //jitne bhi 0s hai add them in queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            //read row, col and dis
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[r][c] = steps;

            int drow[] = {-1,0,+1,0};
            int dcol[] = {0, +1, 0, -1};

            for(int i=0; i<4; i++){
                //new row and new cols for left,right,up,down
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                //if not visited then add them in the queue with new dist
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0){
                    q.push({{nr, nc}, steps+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return dis;
    }
};
