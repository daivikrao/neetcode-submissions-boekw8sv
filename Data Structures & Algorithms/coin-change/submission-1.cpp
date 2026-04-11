class Solution {
public:
    int f(int n,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(n == 0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return INT_MAX;
        }

        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }

        int nottake = 0 + f(n-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[n] <= amount){
            int res = f(n,coins,amount-coins[n],dp);
            if(res != INT_MAX){
                take = res + 1;
            }
        }
        return dp[n][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
