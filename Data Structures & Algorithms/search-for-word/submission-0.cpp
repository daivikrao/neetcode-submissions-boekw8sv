class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i,int j,int idx,vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return false;
        }

        if(visited[i][j]){
            return false;
        }

        if(board[i][j] != word[idx]){
            return false;
        }

        if(idx == word.size()-1){
            return true;
        }

        visited[i][j] = true;
        bool found = dfs(board,word,i+1,j,idx+1,visited) || 
                    dfs(board,word,i-1,j,idx+1,visited) ||
                    dfs(board,word,i,j+1,idx+1,visited) ||
                    dfs(board,word,i,j-1,idx+1,visited);

        visited[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int len = word.size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
