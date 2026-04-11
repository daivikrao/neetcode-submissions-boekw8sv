class Solution {
public:
    bool f(int n,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }

        if(n == 0){
            return nums[0] == target;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        bool notTake = f(n-1,target,nums,dp);
        bool take = false;
        if(nums[n] <= target){
            take = f(n-1,target-nums[n],nums,dp);
        }
        return dp[n][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto& i:nums){
            sum += i;
        }

        if(sum%2!=0){
            return false;
        }

        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));

        return f(n-1,sum/2,nums,dp);
    }
};
