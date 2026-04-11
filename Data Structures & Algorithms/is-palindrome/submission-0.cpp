class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ans += tolower(s[i]);
            }
        }

        int st = 0;
        int e = ans.size() - 1;

        while(st<=e){
            if(ans[st]!=ans[e]){
                return false;
            }
            st += 1;
            e -= 1;
        }
        return true;
    }
};
