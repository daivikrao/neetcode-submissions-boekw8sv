class Solution {
public:
    struct cell{
        int x;
        int y;
        int time;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<cell> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
                
            }
        } 

        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};
        
        int time = 0;

        while(!q.empty()){
            cell f = q.front();
            q.pop();
            time = max(time,f.time);

            for(int i=0;i<4;i++){
                int x = dx[i] + f.x;
                int y = dy[i] + f.y;

                if(x >= 0 && y >= 0 && x < m && y < n && !visited[x][y] && grid[x][y] == 1){
                    q.push({x,y,f.time+1});
                    grid[x][y] = 2;
                    visited[x][y] = true;
                }
            }
        } 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
                
            }
        } 
        return time;
    }
};
