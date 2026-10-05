class Solution {
public:
    int maxNonAdjacent(vector<int>& temp){
        int n = temp.size();
        vector<int> dp(n,0);
        dp[0] = temp[0];

        for(int i=1;i<temp.size();i++){
            int notPick = 0 + dp[i-1];
            int pick = temp[i];
            if(i > 1){
                pick += dp[i-2];
            }
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
    
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
    
        for(int i=0;i<n;i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != n-1){
                temp2.push_back(nums[i]);
            }
        }

        return max(maxNonAdjacent(temp1),maxNonAdjacent(temp2));
    }
};
