class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        vector<int> v;

        for(auto i: nums){
            mp[i] += 1;
        }
        
        for(auto &i: mp){
            pq.push({i.second,i.first});
        }

        while(k!=0){
            v.push_back(pq.top().second);
            pq.pop();
            k -= 1;
        }

        return v;
    }
};
