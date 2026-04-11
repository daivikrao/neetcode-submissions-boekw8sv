class Solution {
public:
    void f(int index,vector<vector<string>>& res,vector<string>& path,string s){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                f(i+1,res,path,s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int st,int e){
        while(st<=e){
            if(s[st]!=s[e]){
                return false;
            }
            st += 1;
            e -= 1;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        f(0,res,path,s);
        return res;
    }
};
