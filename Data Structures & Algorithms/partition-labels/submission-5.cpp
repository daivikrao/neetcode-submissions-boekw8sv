class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mp;
        int n = s.size();

        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }

        int partitionEnd = 0;
        int partitionStart = 0;

        vector<int> partition;

        for(int i=0;i<n;i++){
            partitionEnd = max(partitionEnd,mp[s[i]]);
            if(partitionEnd == i){
                partition.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partition;
    }
};
