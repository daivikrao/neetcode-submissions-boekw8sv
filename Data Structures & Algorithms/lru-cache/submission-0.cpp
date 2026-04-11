class LRUCache {
public:
    unordered_map<int,pair<int,list<int>::iterator>> mp;
    list<int> ls;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        ls.erase(mp[key].second);
        ls.push_front(key);
        mp[key].second = ls.begin();

        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(ls.size() == capacity){
                int last = ls.back();
                ls.pop_back();
                mp.erase(last);
            }
        }else{
            ls.erase(mp[key].second);
        }
        ls.push_front(key);
        mp[key] = {value,ls.begin()};
    }
};
