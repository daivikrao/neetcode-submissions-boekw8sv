class Solution {
public:
    struct cell{
        int x;
        int y;
        int ti;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<cell> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
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
            cell t = q.front();
            q.pop();

            time = max(time, t.ti); 
            for(int i=0;i<4;i++){
                int x = dx[i] + t.x;
                int y = dy[i] + t.y;

                if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && !visited[x][y]){
                    q.push({x,y,t.ti+1});
                    grid[x][y] = 2;
                    visited[x][y] = true;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        } 
        return time;
    }
};
