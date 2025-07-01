// //DFS:
// class Solution {
// public:

//     bool DFS(vector<vector<int>>& graph , int node , vector<int> &color , int currColor) {
//         color[node] = currColor;

//         for(int &v : graph[node]) {
//             if(color[v] == color[node]) {
//                 return false;
//             }

//             if(color[v] == -1) {
//                 color[v] = 1 - color[node];

//                 if(DFS(graph , v , color , color[v]) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();

//         vector<int> color(n , -1);

//         for(int i=0; i<n; i++) {
//             if(color[i] == -1) {
//                 if(DFS(graph , i , color , 1) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };







//BFS:
class Solution {
public:

    bool BFS(vector<vector<int>>& graph , int node , vector<int> &color , int currColor) {
        queue<int> q;
        q.push(node);

        color[node] = currColor;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int &v : graph[curr]) {
                if(color[v] == color[curr]) {
                    return false;
                }

                if(color[v] == -1) {
                    color[v] = 1 - color[curr];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , -1);

        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(BFS(graph , i , color , 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};