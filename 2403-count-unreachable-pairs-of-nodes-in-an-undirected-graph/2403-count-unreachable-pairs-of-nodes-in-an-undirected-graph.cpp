// //DFS:
// class Solution {
// public:

//     void dfs(unordered_map<int , vector<int>> &mpp , int node , vector<bool> &visited , int &cnt) {
//         visited[node] = true;
//         cnt++;

//         for(int &v : mpp[node]) {
//             if(!visited[v]) {
//                 dfs(mpp , v , visited , cnt);
//             }
//         }
//     }

//     long long countPairs(int n, vector<vector<int>>& edges) {
//         int N = edges.size();

//         unordered_map<int , vector<int>> mpp;
//         for(int i=0; i<N; i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             mpp[u].push_back(v);
//             mpp[v].push_back(u);
//         }

//         vector<bool> visited(n , false);

//         unordered_map<int, int> mpp2;

//         int idx = 0;

//         for(int i=0; i<n; i++) {
//             if(!visited[i]) {
//                 int cnt = 0;
//                 dfs(mpp , i , visited , cnt);

//                 mpp2[idx] = cnt;
//                 idx++;
//             }
//         }

//         long long ans = 0;

//         vector<long long> res;
//         for(auto it : mpp2) {
//             res.push_back(it.second);
//         }

//         sort(res.begin() , res.end());

//         vector<long long> prefix(n);
//         prefix[0] = res[0];

//         for(int i=1; i<res.size(); i++) {
//             prefix[i] = prefix[i-1] + res[i];
//         }

//         for(int i=0; i<res.size(); i++) {
//             ans += (long long)((res[i]) * (prefix[res.size() - 1] - res[i]));
//         }
//         return (ans / 2);
//     }
// };







//DSU:
class Solution {
public:

    vector<int> parent;
    vector<int> rank;

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
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int N = edges.size();

        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            Union(u , v);
        }

        unordered_map<int , int> mpp2;

        for(int i=0; i<n; i++) {
            int x = find(i);

            mpp2[x]++;
        }

        long long ans = 0;
        long long cnt = n;

        for(auto it : mpp2) {
            long long t = it.second;

            ans += (long long)(abs((t) * (cnt - t)));
            cnt -= t;
        }
        return ans;
    }
};