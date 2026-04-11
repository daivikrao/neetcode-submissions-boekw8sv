class Solution {
public:
    int f(int n, vector<int>& cost,vector<int>& dp){
        if(n == 0){
            return 0;
        }

        if(n == 1){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int left = f(n-1,cost,dp) + cost[n-1];
        int right = INT_MAX;
        if(n > 1){
            right = f(n-2,cost,dp) + cost[n-2];
        }

        return dp[n] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
       // return f(n,cost,dp);

        dp[0] = 0;
        dp[1] = 0;

        for(int i=2;i<=n;i++){
            int left = dp[i-1] + cost[i-1];
            int right = INT_MAX;
            if(i > 1){
                right = dp[i-2] + cost[i-2];
            }

            dp[i] = min(left,right);
        }
        return dp[n];
    }
};
