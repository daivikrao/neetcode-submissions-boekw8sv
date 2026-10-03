class TrieNode{
    public:
    string word;
    TrieNode* child[26];
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        word = "";
    }
};

class Solution {
public: 
    TrieNode* root = new TrieNode();
    void insert(string word){
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->child[word[i] - 'a'] == NULL){
                curr->child[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->word = word;
    }
    void dfs(vector<vector<char>>& board, int i,int j, vector<string>& ans, TrieNode* node){
        char c = board[i][j];

        if(c == '#' || node->child[c - 'a'] == NULL){
            return;
        }

        node = node->child[c - 'a'];
        if(node->word != ""){
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        for(int k=0;k<4;k++){
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size()){
                dfs(board,x,y,ans,node);
            }
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word: words){
            insert(word);
        }

        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,ans,root);
            }
        }
        return ans;
    }
};
