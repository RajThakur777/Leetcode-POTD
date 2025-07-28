class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;

    public : 
        
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            components = n;
            for(int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
        }
    
        bool isSingle() {
            return components == 1;
        }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {   
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };
        
        sort(edges.begin() , edges.end() , lambda);

        int cnt = 0;

        for(int i=0; i<edges.size(); i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            bool add = false;

            if(type == 3) {
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u , v);
                    add = true;
                }

                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u , v);
                    add = true;
                }

                if(add) {
                    cnt++;
                }
            }
            else if(type == 1) {
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u , v);
                    cnt++;
                }
            }
            else {
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u , v);
                    cnt++;
                }
            }
        }
        if(Alice.isSingle() && Bob.isSingle()) {
            return edges.size() - cnt;
        }
        return -1;
    }
};