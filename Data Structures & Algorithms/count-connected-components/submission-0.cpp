class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& adj,int node){
        visited[node] = 1;

        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(visited,adj,i);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n,0);
        int components = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,adj,i);
                components += 1;
            }
        }
        return components;
    }
};
