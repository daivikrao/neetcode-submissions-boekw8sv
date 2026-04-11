class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodPosition = n - 1;
        for(int i=n-2;i>=0;i--){
            if((i + nums[i]) >= goodPosition){
                goodPosition = i;
            }
        }
        if(goodPosition == 0){
            return true;
        }
        return false;
    }
};
