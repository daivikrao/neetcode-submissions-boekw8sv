class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int maxAns = INT_MIN;
        int n = nums.size();

        for(int i=0;i<=nums.size()-1;i++){
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-1-i];

            maxAns = max(maxAns,max(prefix,suffix));
            if(prefix == 0){
                prefix = 1;
            }

            if(suffix == 0){
                suffix = 1;
            }
        }
        return maxAns;
    }
};
