class Solution {
public:
    void generate(vector<string>& result,int n,int open,int close,string bracket){
        if(bracket.size() == 2*n){
            result.push_back(bracket);
        }

        if(open<n){
            generate(result,n,open+1,close,bracket+"(");
        }
        if(close<open){
            generate(result,n,open,close+1,bracket+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result,n,0,0,"");
        return result;
    }
};
