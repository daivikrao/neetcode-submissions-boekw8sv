class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int components = 0;

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);

                while(!q.empty()){
                    int n = q.front();
                    q.pop();

                    for(auto f: adj[n]){
                        if(!visited[f]){
                            q.push(f);
                            visited[f] = true;
                        }
                    }
                }
                components += 1;
            }
        }
        return components;
    }
};
