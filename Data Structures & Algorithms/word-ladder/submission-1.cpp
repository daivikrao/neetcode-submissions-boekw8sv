class Solution {
public:
    struct node{
        string word;
        int dist;
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visitedSet;
        unordered_set<string> wordListSet(wordList.begin(),wordList.end());

        queue<node> q;
        q.push({beginWord,1});

        visitedSet.insert(beginWord);

        while(!q.empty()){
            node f = q.front();
            q.pop();

            if(f.word == endWord){
                return f.dist;
            }

            for(int i=0;i<f.word.size();i++){
                for(int j=0;j<26;j++){
                    string newWord = f.word;
                    newWord[i] = 'a' + j;
                    if(wordListSet.find(newWord) != wordListSet.end() && visitedSet.find(newWord) == visitedSet.end()){
                        q.push({newWord,f.dist + 1});
                        visitedSet.insert(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
