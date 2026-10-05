class Solution {
public:
    vector<int> dp = vector<int>(50,-1);
    int climbStairs(int n) {

        if(dp[n] != -1){
            return dp[n];
        }

        if(n == 0){
            return 1;
        }

        if(n == 1){
            return 1;
        }

        return dp[n] = climbStairs(n - 1) + climbStairs(n-2);
    }
};
