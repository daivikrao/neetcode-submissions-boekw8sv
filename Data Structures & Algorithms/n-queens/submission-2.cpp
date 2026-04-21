class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int duprow = row;
        int dupcol = col;

        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row -= 1;
            col -= 1;
        }

        row = duprow;
        col = dupcol;

        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col -= 1;
        }

        row = duprow;
        col = dupcol;

        while(row <n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col -= 1;
            row += 1;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>& ans, vector<string>& board,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,ans,board,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));

        solve(0,ans,board,n);
        return ans;
    }
};
