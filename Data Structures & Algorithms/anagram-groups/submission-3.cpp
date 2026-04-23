class Solution {
public:
    string frequencyCheck(string st){
        vector<int> d(26,0);

        for(int i=0;i<st.size();i++){
            d[st[i] - 'a'] += 1;
        }

        string temp = "";
        for(int i=0;i<26;i++){
            if(d[i] != 0){
                temp += char(i + 'a') + to_string(d[i]);
            }
        }
        return temp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        if(strs.size() == 0){
            return ans;
        }
        unordered_map<string,vector<string>> mp;

        for(auto &i: strs){
            string freqStr = frequencyCheck(i);

            mp[freqStr].push_back(i);
        }

        for(auto &i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
