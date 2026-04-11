class Solution {
public:
    void subsetsWithDupHelper(vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int start){
        ans.push_back(temp);

        for(int i=start;i<nums.size();i++){

            if(i>start && nums[i-1] == nums[i]){
                continue;
            }
            temp.push_back(nums[i]);
            subsetsWithDupHelper(ans,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(),nums.end());
        subsetsWithDupHelper(ans,temp,nums,0);
        return ans;
    }
};
