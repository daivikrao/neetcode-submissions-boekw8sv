class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {

        auto &v = mp[key];
        int s = 0;
        int e = v.size() - 1;
        string res = "";

        while(s<=e){
            int mid = (s + e)/2;
            if(v[mid].first == timestamp){
                return v[mid].second;
            }
            else if(v[mid].first < timestamp){
                res = v[mid].second;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return res;
    }
};
