class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());

        while(pq.size() > 1){
            int k1 = pq.top();
            pq.pop();

            int k2 = pq.top();
            pq.pop();

            if(k1 == k2){
                continue;
            }else{
                pq.push(k1 - k2);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};
