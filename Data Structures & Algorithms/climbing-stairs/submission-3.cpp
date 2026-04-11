class Solution {
public:
    int climbStairs(int n) {
        static vector<int> dp(50,-1);

        if(dp[n]!=-1){
            return dp[n];
        }

        if(n == 0){
            return 1;
        }

        if(n == 1){
            return 1;
        }

        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};
