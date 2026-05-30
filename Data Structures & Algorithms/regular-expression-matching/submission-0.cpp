class Solution {
public:
    bool f(int i,int j,string s, string p){
        if(i < 0 && j < 0){
            return true;
        }

        if(j < 0 && i >= 0){
            return false;
        }

        if(i < 0 && j >= 0){
            while(j >= 0){
                if(p[j] == '*'){
                    j -= 2;
                }else{
                    return false;
                }
            }
            return true;
        }

        if(p[j] == s[i] || p[j] == '.'){
            return f(i-1,j-1,s,p);
        }

        if(p[j] == '*'){
            if(p[j-1] != s[i] && p[j-1] != '.'){
                return f(i,j-2,s,p);
            }else{
                return f(i,j-2,s,p) || f(i-1,j,s,p);
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        return f(m-1,n-1,s,p);
    }
};
