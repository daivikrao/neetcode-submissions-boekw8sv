class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLength = 0;
        int hashmap[26] = {0};

        while(r < s.size()){
            hashmap[s[r] - 'A'] += 1;
            maxFreq = max(maxFreq,hashmap[s[r] - 'A']);
            while(((r-l+1) - maxFreq) > k){
                hashmap[s[l] - 'A'] -= 1;
                maxFreq = 0;
                for(int i=0;i<26;i++){
                    maxFreq = max(maxFreq,hashmap[i]);
                }
                l += 1;
            }

            if(((r-l+1) - maxFreq) <= k){
                maxLength = max(maxLength,r-l+1);
            }
            r += 1;
        }
        return maxLength;
    }
};
