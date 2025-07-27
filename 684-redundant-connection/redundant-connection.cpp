//DSU:
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }
        else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {   
        int n = edges.size();

        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1; i<=n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int u1 = find(u);
            int v1 = find(v);

            if(u1 == v1) {
                return {u , v};
            }
            else {
                Union(u , v);
            }
        }
        return {};
    }
};