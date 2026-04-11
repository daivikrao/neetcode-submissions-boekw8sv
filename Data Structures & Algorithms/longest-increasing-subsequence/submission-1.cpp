class Solution {
public:
    int f(int ind,int prevInd,vector<int>& nums,int n){
        if(ind == n){
            return 0;
        }

        int len = 0 + f(ind+1,prevInd,nums,n);
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            len = max(len,1 + f(ind+1,ind,nums,n));
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return f(0,-1,nums,n);
    }
};
