class TrieNode{
    public:
    TrieNode* child[26];
    string word;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
            word = "";
        }
    }
};

void insert(TrieNode* root, string word){
    int n = word.size();

    for(int i=0;i<n;i++){
        if(root->child[word[i] - 'a'] == NULL){
            root->child[word[i] - 'a'] = new TrieNode();
        }
        root = root->child[word[i] - 'a'];
    }
    root->word = word;
}

void dfs(vector<vector<char>>& board,int i, int j, TrieNode* root, vector<string>& ans){
    char c = board[i][j];

    if(root->child[c - 'a'] == NULL || c == '#'){
        return;
    }

    root = root->child[c - 'a'];
    if(root->word != ""){
        ans.push_back(root->word);
        root->word = "";
    }

    board[i][j] = '#';
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};

    for(int k=0;k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];

        if(x>=0 && y>=0 && x<board.size() && y<board[0].size()){
            dfs(board,x,y,root,ans);
        }
    }
    board[i][j] = c;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto &word:words){
            insert(root,word);
        }

        vector<string> ans;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,root,ans);
            }
        }
        return ans;
    }
};
