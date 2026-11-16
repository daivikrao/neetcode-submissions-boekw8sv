class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size()-1;
        int fartest = INT_MIN;
        int jumps = 0;

        while(r < n){
            for(int i=l;i<=r;i++){
                fartest = max(fartest, i + nums[i]);
            }
            l = r + 1;
            r = fartest;
            jumps += 1;
        }
        return jumps;
    }
};
