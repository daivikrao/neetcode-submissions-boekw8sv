class Solution {
public:
    bool f(int n,int target,vector<int>& nums){
        if(target == 0){
            return true;
        }

        if(n == 0){
            return nums[0] == target;
        }

        bool notTake = f(n-1,target,nums);
        bool take = false;
        if(nums[n] <= target){
            take = f(n-1,target-nums[n],nums);
        }
        return take || notTake;
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

        return f(n-1,sum/2,nums);
    }
};
