class TrieNode {
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


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(cur->child[word[i] - 'a'] == NULL){
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] -  'a'];
        }
        cur->isTerminal = true;
    }

    bool searchHelp(TrieNode* root,string word){
        int n = word.size();
        TrieNode* trie = root;
        for(int i=0;i<n;i++)
        {
            if(word[i] == '.')
            {
                for(int j=0;j<26;j++)
                {
                    if(trie->child[j] != NULL && searchHelp(trie->child[j],word.substr(i+1)))
                    {
                        return true;
                    }
                }
                return false;
            }else if(trie->child[word[i] - 'a'] == NULL)
            {
                return false;
            }
            trie = trie->child[word[i] - 'a'];
        }
        return trie->isTerminal;
    }
    
    bool search(string word) {
        return searchHelp(root,word);
    }
};
