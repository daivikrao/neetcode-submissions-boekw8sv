class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpS;
        unordered_map<char,int> mpT;

        for(auto i: s){
            mpS[i] += 1;
        }

        for(auto i: t){
            mpT[i] += 1;
        }

        return mpT == mpS;
    }
};
