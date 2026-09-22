class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();

        vector<bool> ans(n+1,false);

        int maxlen = 0;
        for(auto i:wordDict){
            maxlen = max(maxlen,(int)i.size());
        }

        ans[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(0,i-maxlen);j--){
                if(ans[j] && st.contains(s.substr(j,i-j))){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};
