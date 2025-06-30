//DFS:
// class Solution {
// public:

//     bool dfs(int node , int destination , unordered_map<int , vector<int>> &mpp , vector<bool> &visited) {
//         visited[node] = true;

//         if(node == destination) return true;

//         for(int &v : mpp[node]) {
//             if(!visited[v]) {
//                 if(dfs(v , destination , mpp , visited)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         unordered_map<int , vector<int>> mpp;

//         for(int i=0; i<edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             mpp[u].push_back(v);
//             mpp[v].push_back(u);
//         }

//         vector<bool> visited(n , false);

//         return dfs(source , destination , mpp , visited);
//     }
// };






//BFS:
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>> mpp;

        if(source == destination) return true;

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<bool> visited(n , false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;

            for(int &v : mpp[curr]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};