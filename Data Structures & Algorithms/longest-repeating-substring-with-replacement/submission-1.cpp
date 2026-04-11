class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = INT_MIN;
        int maxLength = 0;
        for(int i=0;i<s.size();i++){
            int hashmap[26] = {0};
            for(int j=i;j<s.size();j++){
                hashmap[s[j] - 'A'] += 1;
                maxFreq = max(maxFreq,hashmap[s[j] - 'A']);
                int changes = (j-i+1) - maxFreq;
                if(changes <= k){
                    maxLength = max(maxLength,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxLength;
    }
};
