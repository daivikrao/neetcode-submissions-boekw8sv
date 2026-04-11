class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int destination = n - 1;
        int coverage = 0;
        int lastJumpIdx = 0;
        int jumps = 0;

        if(n == 1){
            return 0;
        }

        for(int i=0;i<n;i++){
            coverage = max(coverage,i+nums[i]);
            if(i == lastJumpIdx){
                jumps += 1;
                lastJumpIdx = coverage;
            }

            if(lastJumpIdx >= destination){
                return jumps;
            }

        }
        return jumps;
    }
};
