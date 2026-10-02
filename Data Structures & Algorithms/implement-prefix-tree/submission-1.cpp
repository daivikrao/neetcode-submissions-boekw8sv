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
        TrieNode* curr = root;
        for(int i=0;i<n;i++){
            if(curr->child[word[i] - 'a'] == NULL){
                curr->child[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->isTerminal = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* curr = root;
        for(int i=0;i<n;i++){
            if(curr->child[word[i] - 'a'] == NULL){
                return false;
            }
            curr = curr->child[word[i] - 'a'];
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* curr = root;
        for(int i=0;i<n;i++){
            if(curr->child[prefix[i] - 'a'] == NULL){
                return false;
            }
            curr = curr->child[prefix[i] - 'a'];
        }
        return true;
    }
};
