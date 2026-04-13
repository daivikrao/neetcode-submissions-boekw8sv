class Solution {
public:
    bool seen;
    void mark(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }

        if(board[i][j] == 'X'){
            return;
        }

        if(visited[i][j] == false){
            return;
        }

        board[i][j] = 'X';
        mark(board,i-1,j,visited);
        mark(board,i+1,j,visited);
        mark(board,i,j-1,visited);
        mark(board,i,j+1,visited);
    }
    void dfs(vector<vector<char>>& board,int i,int j, vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }
        if(board[i][j] == 'X'){
            return;
        }

        if(visited[i][j] == true){
            return;
        }

        if(i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1){
            seen = true;
        }

        visited[i][j] = true;
        dfs(board,i-1,j,visited);
        dfs(board,i+1,j,visited);
        dfs(board,i,j-1,visited);
        dfs(board,i,j+1,visited);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    seen = false;
                    dfs(board,i,j,visited);
                    if(seen == false){
                        mark(board,i,j,visited);
                    }
                }
            }
        }
    }
};