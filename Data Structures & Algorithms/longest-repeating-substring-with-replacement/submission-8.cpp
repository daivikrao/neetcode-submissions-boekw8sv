class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        int n = s.size();
        int maxFreq = 0;
        int maxLength = 0;
        vector<int> hashmap(26,0);
        
        while(r < n){
            hashmap[s[r] - 'A'] += 1;
            maxFreq = max(maxFreq,hashmap[s[r] - 'A']);
            if((r - l + 1) - maxFreq > k){
                hashmap[s[l] - 'A'] -= 1;
                l += 1;
            }
            if((r - l + 1) - maxFreq <= k){
                maxLength = max(maxLength,r-l+1);
            }
            r += 1;
        }
        return maxLength;
    }
};
