class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        int result = 0;

        for(auto &i: tasks){
            mp[i - 'A'] += 1;
        }

        for(int i=0;i<26;i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
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

            for(auto &f: temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                result += temp.size();
            }else{
                result += n + 1;
            }
        }
        return result;
    }
};
