class Solution {
public:
    void f(vector<vector<string>>& ans, vector<string>& temp, string s, int start){
        if(start == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                f(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int st, int e){
        while(st <= e){
            if(s[st] != s[e]){
                return false;
            }
            st += 1;
            e -= 1;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(ans,temp,s,0);
        return ans;
    }
};
