class Solution {
public:
    void f(int start,vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }

            temp.push_back(candidates[i]);
            f(i+1,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,candidates,target,ans,temp);

        return ans;
    }
};
