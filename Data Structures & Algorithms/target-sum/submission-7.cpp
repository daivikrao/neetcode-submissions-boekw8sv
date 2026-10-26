class Solution {
public:
    int f(int n, vector<int>& nums, vector<vector<int>>& dp,int target){
        if(n == 0){
            if(target == 0 && nums[0] == 0){
                return 2;
            }
            if(target == 0 || nums[0] == target){
                return 1;
            }
            return 0;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int nottake = f(n-1,nums,dp,target);
        int take = 0;
        if(nums[n] <= target){
            take = f(n-1,nums,dp,target-nums[n]);
        }
        return dp[n][target] = take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;

        for(auto i: nums){
            sum += i;
        }

        if((sum - target) < 0 || (sum - target)%2 != 0){
            return false;
        }
        int d = (sum - target)/2;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return f(n-1,nums,dp,d);
    }
};
