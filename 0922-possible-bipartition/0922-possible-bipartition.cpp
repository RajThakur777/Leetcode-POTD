// //DFS:
// class Solution {
// public:

//     bool DFS(unordered_map<int , vector<int>> &mpp , int node , vector<int> &color , int currentColor) {
//         color[node] = currentColor;

//         for(int &v : mpp[node]) {
//             if(color[v] == color[node]) {
//                 return false;
//             }

//             if(color[v] == -1) {
//                 color[v] = 1 - color[node];

//                 if(DFS(mpp , v , color , color[v]) == false) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         unordered_map<int , vector<int>> mpp;

//         int N = dislikes.size();

//         for(int i=0; i<N; i++){
//             int u = dislikes[i][0];
//             int v = dislikes[i][1];

//             mpp[u].push_back(v);
//             mpp[v].push_back(u);
//         }

//         vector<int> color(n+1 , -1);

//         for(int i=1; i<=n; i++) {
//             if(color[i] == -1) {
//                 if(DFS(mpp , i , color , 1) == false) {
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

    bool BFS(unordered_map<int , vector<int>> &mpp , int node , vector<int> &color , int currentColor) {
        queue<int> q;
        q.push(node);

        color[node]= currentColor;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int &v : mpp[curr]) {
                if(color[v] == color[curr]) return false;

                if(color[v] == -1) {
                    color[v] = 1 - color[curr];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int , vector<int>> mpp;

        int N = dislikes.size();

        for(int i=0; i<N; i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int> color(n+1 , -1);

        for(int i=1; i<=n; i++) {
            if(color[i] == -1) {
                if(BFS(mpp , i , color , 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};