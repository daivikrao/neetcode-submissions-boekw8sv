class Solution {
public:
    void f(int start, vector<vector<int>>& ans, vector<int>& temp,vector<int>& nums){
        ans.push_back(temp);

        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            f(i+1,ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(0,ans,temp,nums);
        return ans;
    }
};
