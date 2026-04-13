class Solution {
public:
    struct cell{
        int x;
        int y;
        int min;
    };
    int orangesRotting(vector<vector<int>>& grid) {

        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        queue<cell> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            cell t = q.front();
            q.pop();

            time = max(time,t.min);
            for(int i=0;i<4;i++){
                int tx = t.x + dx[i];
                int ty = t.y + dy[i];

                if(tx>=0 && ty>=0 && tx<m && ty<n && grid[tx][ty]==1 && visited[tx][ty]==false){
                    grid[tx][ty] = 2;
                    visited[tx][ty] = true;
                    q.push({tx,ty,t.min+1});
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
