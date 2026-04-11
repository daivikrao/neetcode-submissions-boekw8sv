class Solution {
public:
    void permuteHelp(vector<vector<int>>& ans,vector<int>& temp,vector<int> nums,int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(auto i:nums){
            int cnt = count(temp.begin(),temp.end(),i);
            if(cnt!=0){
                continue;
            }
            temp.push_back(i);
            permuteHelp(ans,temp,nums,n);

            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        permuteHelp(ans,temp,nums,n);
        return ans;
    }
};
