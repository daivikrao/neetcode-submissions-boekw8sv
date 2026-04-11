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

        for(auto e:edges){
            int pu = findSet(e[0]);
            int pv = findSet(e[1]);

            if(pu == pv){
                return false;
            }

            parent[pu] = pv;
        }
        return true;
    }
};
