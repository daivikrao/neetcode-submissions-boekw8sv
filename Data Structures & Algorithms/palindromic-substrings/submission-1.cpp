class Solution {
public:
    bool isPal(string s,int i, int j){
        if(i>=j){
            return true;
        }

        if(s[i] != s[j]){
            return false;
        }

        return isPal(s,i+1,j-1);
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j)){
                    count += 1;
                }
            }
        }
        return count;
    }
};
