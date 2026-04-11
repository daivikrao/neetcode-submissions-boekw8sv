class Solution {
public:
    void findCombination(int start,vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=start;i<nums.size();i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }

            if(nums[i] > target){
                break;
            }

            temp.push_back(nums[i]);
            findCombination(i+1,ans,temp,nums,target - nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findCombination(0,ans,temp,candidates,target);
        return ans;
    }
};
