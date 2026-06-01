class TrieNode{
    public:
    bool isTerminal;
    TrieNode* child[26];
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
       TrieNode* temp = root;
       int n = word.size();
       for(int i=0;i<n;i++){
            if(temp->child[word[i] - 'a'] == NULL){
                temp->child[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->child[word[i] - 'a'];
       }
       temp->isTerminal = true;
    }

    bool searchHelp(TrieNode* root, string word){
        TrieNode* temp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(word[i] == '.'){
                for(int j=0;j<26;j++){
                    if(temp->child[j] != NULL && searchHelp(temp->child[j],word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }else if(temp->child[word[i] - 'a'] == NULL){
                return false;
            }
            temp = temp->child[word[i] - 'a'];
        }
        return temp->isTerminal;
    }
    
    bool search(string word) {
        return searchHelp(root,word);
    }
};
