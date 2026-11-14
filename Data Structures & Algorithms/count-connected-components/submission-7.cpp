class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int components = 0;

        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n,false);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int f = q.front();
                    q.pop();

                    for(auto j:adj[f]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
                components += 1;
            }
        }
        return components;
    }
};
