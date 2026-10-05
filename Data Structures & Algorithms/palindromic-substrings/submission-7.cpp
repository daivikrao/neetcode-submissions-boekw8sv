class Solution {
public:
    bool isPal(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j){
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] != s[j]){
            return false;
        }

        return dp[i][j] = isPal(i+1,j-1,s,dp);
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(i,j,s,dp)){
                    count += 1;
                }
            }
        }
        return count;
    }
};
