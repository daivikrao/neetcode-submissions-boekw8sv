class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hashMap(26,0);
        priority_queue<int> pq;
        int res = 0;

        for(auto i: tasks){
            hashMap[i - 'A'] += 1;
        }

        for(int i=0;i<26;i++){
            if(hashMap[i] != 0){
                pq.push(hashMap[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f -= 1;
                    temp.push_back(f);
                }
            }

            for(auto &i: temp){
                if(i > 0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                res += temp.size();
            }else{
                res += n+1;
            }
        }
        return res;
    }
};
