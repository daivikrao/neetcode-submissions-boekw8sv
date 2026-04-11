class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n,0);
        queue<int> q;
        int components = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it: adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
                components += 1;
            }
        }
        return components;
    }
};
