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

        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,0));

        //return f(n-1,sum/2,nums,dp);

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(nums[0] <= sum/2){
            dp[0][nums[0]] = true;
        }
        

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][sum/2];
    }
};
