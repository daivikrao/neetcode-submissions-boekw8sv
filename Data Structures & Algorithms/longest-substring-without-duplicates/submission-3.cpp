class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int n = s.size();
        vector<int> hashmap(255,-1);

        while(r < n){

            if(hashmap[s[r]] != -1){
                if(hashmap[s[r]] >= l){
                    l = hashmap[s[r]] + 1;
                }
            }
            int length = r - l + 1;
            maxLen = max(maxLen,length);
            hashmap[s[r]] = r;
            r += 1;
        }
        return maxLen;
    }
};
