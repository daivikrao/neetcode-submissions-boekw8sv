class Solution {
public:
    struct cell{
        int x;
        int y;
    };
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};

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
                int x1 = t.x + dx[i];
                int y1 = t.y + dy[i];

                if(x1>=0 && y1>=0 && x1<m && y1<n && grid[x1][y1] == INT_MAX){
                    grid[x1][y1] = grid[t.x][t.y] + 1;
                    q.push({x1,y1});
                }
            }
        }
    }
};
