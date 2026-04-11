class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        int longest = 1;

        for(auto i: mp){
            if(mp.find(i-1) == mp.end()){
                int cnt = 1;
                int x = i;
                while(mp.find(x+1) != mp.end()){
                    x = x + 1;
                    cnt += 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
