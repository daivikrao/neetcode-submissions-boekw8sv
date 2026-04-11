class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &t: flights){
            adj[t[0]].push_back({t[1],t[2]});
        }

        //{cost,node,stops}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,0});

        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int cost = it[0];
            int node = it[1];
            int stops = it[2];

            if(node == dst){
                return cost;
            }

            if(stops > k){
                continue;
            }

            for(auto &i: adj[node]){
                int price = i.second;
                int next = i.first;
                if(cost + price < dist[next][stops+1]){
                    dist[next][stops+1] = cost + price;
                    pq.push({cost+price,next,stops+1});
                }
            }
        }
        return -1;
    }
};
