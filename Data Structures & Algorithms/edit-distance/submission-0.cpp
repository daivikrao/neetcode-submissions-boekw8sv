class Solution {
public:
    int f(int i,int j,string word1, string word2){
        if(i < 0){
            return j + 1;
        }

        if(j < 0){
            return i + 1;
        }

        if(word1[i] == word2[j]){
            return f(i-1,j-1,word1,word2);
        }

        return 1 + min(f(i-1,j,word1,word2),min(f(i-1,j-1,word1,word2),f(i,j-1,word1,word2)));
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return f(m-1,n-1,word1,word2);
    }
};
