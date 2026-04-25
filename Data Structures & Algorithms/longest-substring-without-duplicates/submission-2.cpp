class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        vector<int> hash(255,-1);
        int n = s.size();
        int maxLen = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int length = r - l + 1;
            maxLen = max(maxLen,length);
            hash[s[r]] = r;
            r += 1;
        }
        return maxLen;
    }
};
