class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        if(nums.size() == 0){
            return 0;
        }

        int longest = INT_MIN;

        for(auto i: nums){
            if(st.count(i-1) == false){
                int x = i;
                int cnt = 1;

                while(st.find(x+1) != st.end()){
                    cnt += 1;
                    x += 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
