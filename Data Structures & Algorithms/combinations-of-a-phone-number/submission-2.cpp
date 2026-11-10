class Solution {
public:
    void f(int ind, string comb, vector<string>& ans, string digits, unordered_map<char,string>& mp){
        if(comb.size() == digits.size()){
            ans.push_back(comb);
            return;
        }

        string letters = mp[digits[ind]];
        for(auto letter: letters){
            f(ind+1,comb + letter, ans, digits,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.size() == 0){
            return ans;
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

        f(0,"",ans,digits,mp);
        return ans;
    }
};
