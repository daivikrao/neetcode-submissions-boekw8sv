class Solution {
public:
    vector<int> parent;

    void makeSet(int V){
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
    }

    int findSet(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findSet(parent[x]);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }

        makeSet(n);
        for(auto i: edges){
            int u = i[0];
            int v = i[1];

            int pu = findSet(u);
            int pv = findSet(v);

            if(pu == pv){
                return false;
            }

            parent[pu] = pv;
        }
        return true;
    }
};
