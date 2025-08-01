// //DSU:
// class Solution {
// public:

//     vector<int> parent;
//     vector<int> rank;

//     int find(int x) {
//         if(x == parent[x]) return x;

//         return parent[x] = find(parent[x]);
//     }

//     void Union(int x , int y) {
//         int parent_x = find(x);
//         int parent_y = find(y);

//         if(parent_x == parent_y) return;

//         if(rank[parent_x] > rank[parent_y]) {
//             parent[parent_y] = parent_x; 
//         }
//         else if(rank[parent_y] > rank[parent_x]) {
//             parent[parent_x] = parent_y;
//         }
//         else {
//             parent[parent_y] = parent_x;
//             rank[parent_x]++;
//         }
//     }

//     int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) { 
//         parent.resize(n);
//         rank.resize(n , 0);

//         for(int i=0; i<n; i++) {
//             parent[i] = i;
//         }  

//         set<int> st;
//         for(int i=0; i<restricted.size(); i++) {
//             st.insert(restricted[i]);
//         }

//         int cnt = 0;

//         for(int i=0; i<edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             int parent_u = find(u);
//             int parent_v = find(v);

//             if((st.find(u) != st.end()) || (st.find(v) != st.end()) || (parent_u == parent_v)) {
                
//                 continue;
//             }

//             Union(u , v);
//         }

//         for(int i=0; i<n; i++) {
//             if(st.find(i) == st.end() && find(i) == find(0)) {
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };






//DFS:
class Solution {
public:

    int dfs(int node , unordered_map<int , vector<int>> &mpp , vector<bool> &visited , set<int> &st) {
        int cnt = 0;

        visited[node] = true;
        cnt++;

        for(auto it : mpp[node]) {
            if(!visited[it] && st.find(it) == st.end()) {
                cnt += dfs(it , mpp , visited , st);
            }
        }
        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) { 
        int N = edges.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<bool> visited(n , false);

        set<int> st;
        for(int i=0; i<restricted.size(); i++) {
            st.insert(restricted[i]);
        }

        return dfs(0 , mpp , visited , st);
    }
};