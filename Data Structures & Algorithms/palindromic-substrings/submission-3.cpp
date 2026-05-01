class Solution {
public:
    bool isPal(string s,int i, int j,vector<vector<int>>& dp){
        if(i>=j){
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i] != s[j]){
            return false;
        }

        return dp[i][j] = isPal(s,i+1,j-1,dp);
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j,dp)){
                    count += 1;
                }
            }
        }
        return count;
    }
};
