class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        vector<vector<int>> result(k);

        for(auto& p: points){
            int x = p[0];
            int y = p[1];
            maxHeap.push({x*x+y*y,{x,y}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        for(int i=0;i<k;i++){
            pair<int,pair<int,int>> t = maxHeap.top();
            maxHeap.pop();
            result[i] = {t.second.first,t.second.second};
        }
        return result;
    }
};
