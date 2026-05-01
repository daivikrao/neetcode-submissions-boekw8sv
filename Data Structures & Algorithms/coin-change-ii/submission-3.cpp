class Solution {
public:
    int f(int n, vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(n == 0){
            return (amount%coins[0] == 0);
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        int nottake = f(n-1,coins,amount,dp);
        int take = 0;
        if(coins[n] <= amount){
            take = f(n,coins,amount-coins[n],dp);
        }
        return dp[n][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }
};
