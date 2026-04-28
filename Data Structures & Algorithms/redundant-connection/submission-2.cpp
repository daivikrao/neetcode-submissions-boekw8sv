class Solution {
public:
    vector<int> parent;

    void makeSet(int V){
        parent.resize(V+1);
        for(int i=1;i<=V;i++){
            parent[i] = i;
        }
    }

    int findSet(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findSet(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        makeSet(n+1);

        for(auto e:edges){
            int u = e[0];
            int v = e[1];

            int pu = findSet(u);
            int pv = findSet(v);

            if(pu == pv){
                return e;
            }

            parent[pu] = pv;
        }
        return {};
    }
};
