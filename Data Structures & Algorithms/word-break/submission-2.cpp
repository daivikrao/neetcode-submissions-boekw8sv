class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();

        int len = 0;
        vector<bool> ans(n+1,false);

        for(int i=0;i<wordDict.size();i++){
            len = max(len,(int)wordDict[i].size());
        }

        ans[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(0,i-len);j--){
                if(ans[j] && st.contains(s.substr(j,i-j))){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};
