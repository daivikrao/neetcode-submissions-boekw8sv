class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int> &temp, int i,vector<int>& nums,int target){
        if(i == nums.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            combination(ans,temp, i,nums,target - nums[i]);
            temp.pop_back();
        }
        combination(ans,temp, i+1,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        combination(ans,temp,0, nums,target);
        return ans;
    }
};
