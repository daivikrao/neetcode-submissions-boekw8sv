class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxFreq = 0;
        int longest = 1;
        vector<int> hashMap(26,0);

        while(r < n){
            hashMap[s[r] - 'A'] += 1;
            maxFreq = max(maxFreq,hashMap[s[r] - 'A']);

            if((r-l+1) - maxFreq > k){
                hashMap[s[l] - 'A'] -= 1;
                l += 1;
            }

            if((r-l+1) - maxFreq <= k){
                longest = max(longest,r-l+1);
            }
            r += 1;
        }
        return longest;
    }
};
