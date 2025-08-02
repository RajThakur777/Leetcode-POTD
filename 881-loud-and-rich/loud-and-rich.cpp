class Solution {
public:

    int dfs(int node , vector<bool> &visited , unordered_map<int , vector<int>> &mpp , vector<int> &quiet) {
        visited[node] = true;
        int ans = node;

        for(auto it : mpp[node]) {
            if(!visited[it]) {
                int t = dfs(it , visited , mpp , quiet);

                if(quiet[t] < quiet[ans]) {
                    ans = t;
                }
            }
        }
        return ans;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<int> ans(n);

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<richer.size(); i++) {
            mpp[richer[i][1]].push_back(richer[i][0]);
        }

        for(int i=0; i<n; i++) {
            vector<bool> visited(n , false);

            int y = INT_MAX;

            y = dfs(i , visited , mpp , quiet);

            if(y == INT_MAX) {
                ans[i] = i;
            }
            else {
                ans[i] = y;
            }
        }
        return ans;
    }
};






// class Solution {
// public:
    
//     void dfs(vector<int> adj[],int node,vector<int>& vis,int& ans,int& mini,vector<int>& quiet){
//         vis[node] = 1;
//         if(quiet[node]<mini){
//             mini = quiet[node];
//             ans = node;
//         }
        
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfs(adj,it,vis,ans,mini,quiet);
//             }
//         }
//     }
    
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         int n = quiet.size();
//         vector<int> adj[n];
//         for(auto it : richer){
//             adj[it[1]].push_back(it[0]);
//         }
//         vector<int> ans(n,-1);
//         for(int i = 0;i<n;i++){
//             vector<int> vis(n,0);
//             int mini = INT_MAX;
//             dfs(adj,i,vis,ans[i],mini,quiet);
//         }
//         return ans;
//     }
// };