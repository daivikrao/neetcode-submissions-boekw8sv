class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        unordered_map<int,int> mp;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int currDist = p.first;
            int node = p.second;

            if(visited[node]){
                continue;
            }

            visited[node] = true;
            for(auto &i : adj[node]){
                if(!visited[i.first] && currDist + i.second < dist[i.first]){
                    dist[i.first] = currDist + i.second;
                    pq.push({currDist + i.second,i.first});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i] == INT_MAX){
                mp[i] = -1;
            }
            else{
                mp[i] = dist[i];
            }
        }
        return mp;
    }
};
