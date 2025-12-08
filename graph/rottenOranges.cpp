class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //row, col, time
        queue<pair<pair<int,int>, int>> q;
        //visited array banaya hai naya 
        int vis[n][m];
        //here we are traversing through the grid and pushing the rotten {r,c,time} in our queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;          //also mark visted array me
                }
                else{
                    vis[i][j] =0;      
                }
            }
        }

        int time = 0;
        //possible combinations of row and col ki separate array banali
        int drow[] = {-1,0,+1,0};     
        int dcol[] = {0,+1,0,-1};

        //jab tak q empty ni hota tab tak push-pop
        while(!q.empty()){
            //row,col,time ko read krliya front of queue se
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            //here we are creating possible places we can visit from curr node
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] !=2 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        //finally checking ki agar koi node abhi bhi 1 reh gyi hai mtlb cant be reached
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
            }
        }
        return time;
    }
};
