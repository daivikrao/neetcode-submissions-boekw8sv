class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int osum = (n*(n+1))/2;
        int asum = 0;

        for(int i=0;i<n;i++){
            asum += nums[i];
        }

        return osum - asum;
    }
};
