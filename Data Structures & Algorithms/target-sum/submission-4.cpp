class Solution {
public:
    int f(int n,vector<int>& nums, int target,vector<vector<int>>& dp){
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
        int nottake = f(n-1,nums,target,dp);
        int take = 0;
        if(nums[n] <= target){
            take = f(n-1,nums,target-nums[n],dp);
        }
        return dp[n][target] = take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for(auto i:nums){
            totalSum += i;
        }

        if((totalSum - target) < 0 || (totalSum - target)%2 !=0){
            return false;
        }

        int d = (totalSum - target)/2;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return f(n-1,nums,d,dp);
    }
};
