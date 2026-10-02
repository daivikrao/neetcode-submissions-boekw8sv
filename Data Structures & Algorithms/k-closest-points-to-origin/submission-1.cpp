class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> result(k);

        for(auto &i: points){
            int x = i[0];
            int y = i[1];

            pq.push({x*x+y*y,{x,y}});
            if(pq.size() > k){
                pq.pop();
            }
        }

        for(int i=0;i<k;i++){
            pair<int, pair<int,int>> t = pq.top();
            pq.pop();

            result[i] = {t.second.first,t.second.second};
        }
        return result;
    }
};
