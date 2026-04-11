class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        vector<bool> visited(n+1,false);

        priority_queue<pair<int,int>, vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [currDist, node] = pq.top();
            pq.pop();

            if(visited[node]){
                continue;
            }
            visited[node] = true;

            for(auto &[v,weight]: adj[node]){
                if(!visited[v] && currDist + weight < dist[v]){
                    dist[v] = currDist + weight;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
