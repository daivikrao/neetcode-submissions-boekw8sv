class Solution {
public:
    bool seen;
    void mark(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return;
        }

        if(board[i][j] == 'X'){
            return;
        }

        board[i][j] = 'X';
        mark(board,visited,i+1,j);
        mark(board,visited,i-1,j);
        mark(board,visited,i,j+1);
        mark(board,visited,i,j-1);
    }
    void dfs(int i,int j, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }

        if(board[i][j] == 'X'){
            return;
        }

        if(visited[i][j]){
            return;
        }

        if(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() -1){
            seen = true;
        }
        visited[i][j] = true;
        dfs(i+1,j,board,visited);
        dfs(i-1,j,board,visited);
        dfs(i,j-1,board,visited);
        dfs(i,j+1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    seen = false;
                    dfs(i,j,board,visited);
                    if(seen == false){
                        mark(board,visited,i,j);
                    }
                }
            }
        }
    }
};
