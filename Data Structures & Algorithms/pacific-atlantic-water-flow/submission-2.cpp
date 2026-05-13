class Solution {
public:
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& visited){
        int m = heights.size();
        int n = heights[0].size();

        visited[i][j] = true;
        if(i+1 < m && visited[i+1][j] == false && heights[i+1][j] >= heights[i][j]){
            dfs(heights,i+1,j,visited);
        }

        if(j+1 < n && visited[i][j+1] == false && heights[i][j+1] >= heights[i][j]){
            dfs(heights,i,j+1,visited);
        }

        if(i-1 >= 0 && visited[i-1][j] == false && heights[i-1][j] >= heights[i][j]){
            dfs(heights,i-1,j,visited);
        }

        if(j-1 >= 0 && visited[i][j-1] == false && heights[i][j-1] >= heights[i][j]){
            dfs(heights,i,j-1,visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            dfs(heights,0,j,pacific);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,0,pacific);
        }

        for(int j=0;j<n;j++){
            dfs(heights,m-1,j,atlantic);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,n-1,atlantic);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
