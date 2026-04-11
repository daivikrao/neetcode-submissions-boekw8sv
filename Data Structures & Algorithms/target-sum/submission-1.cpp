class Solution {
public:
    int f(int n,vector<int>& nums, int target){
        if(n == 0){
            if(target == 0 && nums[0] == 0){
                return 2;
            }
            if(target == 0 || nums[0] == target){
                return 1;
            }
            return 0;
        }

        int nottake = f(n-1,nums,target);
        int take = 0;
        if(nums[n] <= target){
            take = f(n-1,nums,target-nums[n]);
        }
        return take + nottake;
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
        return f(n-1,nums,d);
    }
};
