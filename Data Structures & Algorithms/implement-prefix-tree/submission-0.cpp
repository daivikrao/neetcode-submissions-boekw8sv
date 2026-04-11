class TrieNode{
    public:
    bool isTerminal;
    TrieNode* child[26];
    TrieNode(){
        isTerminal = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            if(cur->child[word[i] - 'a'] == NULL){
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->isTerminal = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* cur = root;
        for(int i=0;i<n;i++){
            if(cur->child[word[i] - 'a'] == NULL){
                return false;
            }
            cur = cur->child[word[i] - 'a'];
        }
        return cur->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0;i<prefix.size();i++){
            if(cur->child[prefix[i] - 'a'] == NULL){
                return false;
            }
            cur = cur->child[prefix[i] - 'a'];
        }
        return true;
    }
};
