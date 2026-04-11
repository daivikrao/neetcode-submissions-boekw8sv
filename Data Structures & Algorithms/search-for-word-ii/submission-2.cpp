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

class Solution {
public:
    void insert(TrieNode* root, string word){
        TrieNode* curr = root;
        for(auto i:word){
            if(curr->child[i - 'a'] == NULL){
                curr->child[i - 'a'] = new TrieNode();
            }
            curr = curr->child[i - 'a'];
        }
        curr->word = word;
    }
    void dfs(vector<vector<char>>& board, int i,int j,TrieNode* node, vector<string>& ans){
        char c = board[i][j];

        if(node->child[c - 'a'] == NULL || c == '#'){
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
            int x = i + dx[k];
            int y = j + dy[k];

            if(x>=0 && y>=0 && x<board.size() && y<board[0].size()){
                dfs(board,x,y,node,ans);
            }
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto& word: words){
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
