class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();
        int minLength = INT_MAX;
        int startIndex = -1;

    
        for(int i=0;i<n;i++){
            int cnt = 0;
            vector<int> mp(256,0);
            for(int j=0;j<m;j++){
                mp[t[j]] += 1;
            }
            for(int j=i;j<n;j++){
                if(mp[s[j]] > 0){
                    cnt += 1;
                }
                mp[s[j]] -= 1;
                if(cnt == m){
                    if((j-i+1) < minLength){
                        minLength = j-i+1;
                        startIndex = i;
                        break;
                    }
                }
            }
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
