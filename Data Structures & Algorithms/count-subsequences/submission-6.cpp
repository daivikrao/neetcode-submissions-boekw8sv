class Solution {
public:
    int f(int i, int j, string s, string p, vector<vector<int>>& dp){
        if(j < 0){
            return 1;
        }

        if(i < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == p[j]){
            return dp[i][j] = f(i-1,j-1,s,p,dp) + f(i-1,j,s,p,dp);
        }

        return dp[i][j] = f(i-1,j,s,p,dp);
    }
    int numDistinct(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1,m-1,s,p,dp);
    }
};
