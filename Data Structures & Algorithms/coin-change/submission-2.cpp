class Solution {
public:
    int f(int n,vector<int>& coins, vector<vector<int>>& dp,int amount){
        if(n == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            return INT_MAX;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int notTake = 0 + f(n-1,coins,dp,amount);
        int take = INT_MAX;
        if(coins[n] <= amount){
            int res = f(n,coins,dp,amount-coins[n]);
            if(res != INT_MAX){
                take = res + 1;
            }
        }

        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = f(n-1,coins,dp,amount);
        if(ans == INT_MAX){
            return -1;
        }return ans;
    }
};
