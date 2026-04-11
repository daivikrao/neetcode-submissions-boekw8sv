class Solution {
public:
    void backtracking(int idx, string col,vector<string>& res,string digits,unordered_map<char,string> mp){
        if(idx == digits.size()){
            res.push_back(col);
            return;
        }

        string letters = mp[digits[idx]];
        for(auto letter: letters){
            backtracking(idx+1,col+letter,res,digits,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if(digits.empty()){
            return res;
        }

        unordered_map<char,string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        backtracking(0,"",res,digits,mp);
        return res;
    }
};
