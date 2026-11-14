class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }

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

    void unionSet(int u, int v){
        int pu = findSet(u);
        int pv = findSet(v);

        if(pu != pv){
            parent[pu] = pv;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                edges.push_back({i,j,cost});
            }
        }

        makeSet(n);
        sort(edges.begin(),edges.end(),cmp);

        int minWts = 0;
        int edgeUsed = 0;

        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if(findSet(u) != findSet(v)){
                minWts += cost;
                edgeUsed += 1;
                unionSet(u,v);

                if(edgeUsed == n - 1){
                    break;
                }
            }
        }
        return minWts;
    }
};
