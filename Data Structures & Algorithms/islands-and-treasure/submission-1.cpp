class Solution {
public:
    struct cell{
        int x;
        int y;
    };
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        queue<cell> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            cell t = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x = dx[i] + t.x;
                int y = dy[i] + t.y;

                if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == INT_MAX){
                    grid[x][y] = grid[t.x][t.y] + 1;
                    q.push({x,y});
                }
            }
        }
    }
};
