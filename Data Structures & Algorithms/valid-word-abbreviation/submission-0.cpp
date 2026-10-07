class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;

        while(i < word.size() && j < abbr.size()){
            if(isalpha(abbr[j])){
                if(word[i] != abbr[j]){
                    return false;
                }
                i += 1;
                j += 1;
            }else if(abbr[j] == '0'){
                return false;
            }else{
                int num = 0;
                while(j < abbr.size() && isdigit(abbr[j])){
                    num = num*10 + (abbr[j] - '0');
                    j += 1;
                }
                i += num;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};