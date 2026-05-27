class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(auto &i: nums){
            int cnt = count(temp.begin(),temp.end(),i);
            if(cnt != 0){
                continue;
            }
            temp.push_back(i);
            f(ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(ans,temp,nums);

        return ans;
    }
};
