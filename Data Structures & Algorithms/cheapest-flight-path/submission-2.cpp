class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto t: flights){
            adj[t[0]].push_back({t[1],t[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;

        pq.push({0,src,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int currDist = it[0];
            int node = it[1];
            int stops = it[2];

            if(node == dst){
                return currDist;
            }

            if(stops > k){
                continue;
            }

            for(auto f: adj[node]){
                int v = f.first;
                int cost = f.second;

                if(cost + currDist < dist[v][stops+1]){
                    dist[v][stops+1] = cost + currDist;
                    pq.push({dist[v][stops+1],v,stops+1});
                }
            }
        }
        return -1;
    }
};
