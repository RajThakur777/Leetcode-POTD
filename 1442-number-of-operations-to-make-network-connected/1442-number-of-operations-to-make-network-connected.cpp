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
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int N = connections.size();

        if(N < n-1) return -1;

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int components = n;

        for(auto &vec : connections) {
            if(find(vec[0]) != find(vec[1])) {
                Union(vec[0] , vec[1]);
                components--;
            }
        }
        return components - 1;
    }
};