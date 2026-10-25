class Solution {
public:
    bool f(int n, vector<int>& nums, int target,vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }

        if(n == 0){
            return nums[0] == target;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        int notTake = f(n-1,nums,target,dp);
        int take = false;
        if(nums[n] <= target){
            take = f(n-1,nums,target-nums[n],dp);
        }

        return dp[n][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(auto i: nums){
            sum += i;
        }

        if(sum%2 != 0){
            return false;
        }

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return f(n-1,nums,sum/2,dp);
    }
};
