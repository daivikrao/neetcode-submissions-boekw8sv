class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int s = 0;
        int e = nums.size()-1;

        while(s<=e){
            int mid = (s+e)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;

            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
                return nums[mid];
            }else if(nums[mid] <= nums[e]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }
};
