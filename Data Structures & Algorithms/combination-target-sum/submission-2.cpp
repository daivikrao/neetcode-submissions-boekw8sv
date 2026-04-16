class Solution {
public:
    void backtrack(int i, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans){
        if(i == nums.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        if(nums[i] <= target){
            curr.push_back(nums[i]);
            backtrack(i,nums,target-nums[i],curr,ans);
            curr.pop_back();
        }

        backtrack(i+1,nums,target,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,nums,target,curr,ans);
        return ans;
    }
};
