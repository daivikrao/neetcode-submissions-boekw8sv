class Solution {
public:
    int f(int n,vector<int>& coins, int amount){
        if(n == 0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return INT_MAX;
        }

        int nottake = 0 + f(n-1,coins,amount);
        int take = INT_MAX;
        if(coins[n] <= amount){
            int res = f(n,coins,amount-coins[n]);
            if(res != INT_MAX){
                take = res + 1;
            }
        }
        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n-1,coins,amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
