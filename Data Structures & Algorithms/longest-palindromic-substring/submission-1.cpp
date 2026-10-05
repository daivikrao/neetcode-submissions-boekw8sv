class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1){
            return s;
        }

        string LPS = "";

        for(int i=1;i<s.size();i++){
            int low = i;
            int high = i;

            while(low>=0 && high<s.size() && s[low] == s[high]){
                low -= 1;
                high += 1;

                if(low == -1 || high == s.size()){
                    break;
                }
            }

            string palindrome = s.substr(low+1,high-low-1);
            if(palindrome.size() > LPS.size()){
                LPS = palindrome;
            }

            low = i-1;
            high = i;

            while(low>=0 && high<s.size() && s[low] == s[high]){
                low -= 1;
                high += 1;

                if(low == -1 || high == s.size()){
                    break;
                }
            }

            palindrome = s.substr(low+1,high-low-1);
            if(palindrome.size() > LPS.size()){
                LPS = palindrome;
            }
        }
        return LPS;
    }
};
