class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }

        vector<int> partition;
        int partitionStart = 0;
        int partitionEnd = 0;

        for(int i=0;i<s.size();i++){
            partitionEnd = max(partitionEnd,mp[s[i]]);
            if(partitionEnd == i){
                partition.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partition;
    }
};
