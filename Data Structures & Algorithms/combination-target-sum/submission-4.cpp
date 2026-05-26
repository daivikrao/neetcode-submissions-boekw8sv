class Solution {
public:
    void f(int i,vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int target){
        if(i == nums.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            f(i,ans,temp,nums,target-nums[i]);
            temp.pop_back();
        }
        f(i+1,ans,temp,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(0,ans,temp,nums,target);

        return ans;
    }
};
