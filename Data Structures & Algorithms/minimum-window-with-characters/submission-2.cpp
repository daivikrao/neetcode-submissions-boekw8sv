class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;

        int n = s.size();
        int m = t.size();
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;

        vector<int> mp(256,0);

        for(int i=0;i<m;i++){
            mp[t[i]] += 1;
        }

        while(r < n){
            if(mp[s[r]] > 0){
                count += 1;
            }
            mp[s[r]] -= 1;
            while(count == m){
                if((r - l + 1) < minLength){
                    minLength = r - l + 1;
                    startIndex = l;
                }
                mp[s[l]] += 1;
                if(mp[s[l]] > 0){
                    count -= 1;
                }
                l += 1;
            }
            r += 1;
        }
        return startIndex == -1 ? "" : s.substr(startIndex,minLength);

    }

};
