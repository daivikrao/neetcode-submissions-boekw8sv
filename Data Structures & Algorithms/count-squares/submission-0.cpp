class CountSquares {
public:
    map<pair<int,int>,int> mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}] += 1;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0];
        int y = point[1];

        for(auto it:mp){
            pair<int,int> t = it.first;
            if(t.first != x && t.second != y && (abs(t.first - x)==abs(t.second - y))){
                int f1 = mp[{t.first,t.second}];
                int f2 = mp[{t.first,y}];
                int f3 = mp[{x,t.second}];
                count += f1*f2*f3;
            }
        }
        return count;
    }
};
