class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,vector<vector<bool>>& visited,int idx,int i,int j){
        if(i < 0 || j < 0 || i>=board.size() || j>=board[0].size()){
            return false;
        }

        if(visited[i][j]){
            return false;
        }

        if(board[i][j] != word[idx]){
            return false;
        }

        if(idx == word.size() - 1){
            return true;
        }

        visited[i][j] = true;
        bool found = dfs(board,word,visited,idx+1,i+1,j) ||
                    dfs(board,word,visited,idx+1,i-1,j) ||
                    dfs(board,word,visited,idx+1,i,j+1) ||
                    dfs(board,word,visited,idx+1,i,j-1);
        visited[i][j] = false;
        return found;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int k=0;k<words.size();k++){
            bool f = false;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(dfs(board,words[k],visited,0,i,j)){
                        ans.push_back(words[k]);
                        f = true;
                        break;
                    }
                }
                if(f){
                    break;
                }
            }
        }
        return ans;
    }
};
