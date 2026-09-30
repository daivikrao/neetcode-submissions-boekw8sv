class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                return true;
            }else{
                mp[nums[i]] += 1;
            }
        }
        return false;
    }
};