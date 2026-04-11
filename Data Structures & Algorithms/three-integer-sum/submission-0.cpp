class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> ans;
         sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i + 1;
            int k = n - 1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j += 1;
                }else if(sum > 0){
                    k -= 1;
                }else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j += 1;
                    k -= 1;

                    while(j<k && nums[j] == nums[j-1]){
                        j += 1;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k -= 1;
                    }
                }
            }
        }
        return ans;
    }
};
