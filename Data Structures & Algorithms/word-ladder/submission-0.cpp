class Solution {
public:
    struct node{
        string word;
        int dist;
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> visited;
      unordered_set<string> validwordlist;

      for(int i=0;i<wordList.size();i++){
        validwordlist.insert(wordList[i]);
      }  

      queue<node> q;
      q.push({beginWord,1});

      visited.insert(beginWord);

      while(!q.empty()){
        node t = q.front();
        q.pop();

        if(t.word == endWord){
            return t.dist;
        }

        for(int i=0;i<t.word.size();i++){
            for(int j=0;j<26;j++){
                string newWord = t.word;
                newWord[i] = 'a' + j;
                if(validwordlist.find(newWord) != validwordlist.end() && visited.find(newWord) == visited.end()){
                    q.push({newWord,t.dist+1});
                    visited.insert(newWord);
                }
            }
        }
      }
      return 0;
    }
};
