class Solution {
public:
    string getFrequency(string s){
        vector<int> d(26,0);

        for(auto i:s){
            d[i - 'a'] += 1;
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
        for(auto i: strs){
            string frequencyString = getFrequency(i);

            mp[frequencyString].push_back(i);
        }

        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
