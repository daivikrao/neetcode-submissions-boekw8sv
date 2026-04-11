class Solution {
public:
    void subsetsHelper(vector<vector<int>>& ans,vector<int> &temp,int start,vector<int> nums){
        ans.push_back(temp);

        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            subsetsHelper(ans,temp,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        subsetsHelper(ans,temp,0,nums);
        return ans;
    }
};
