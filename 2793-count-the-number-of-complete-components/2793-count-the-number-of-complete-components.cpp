class Solution {
public:

    void dfs(vector<vector<int>> &adj , vector<bool> &vis , int node , int &vertex , int &edges){
        vertex++;
        vis[node] = true;

        edges += adj[node].size();

        for(auto neigh : adj[node]){
            if(vis[neigh] == false){
                dfs(adj , vis , neigh , vertex , edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n , false);

        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            if(vis[i] == false){
                int v=  0;
                int e = 0;
                
                dfs(adj , vis , i , v , e);

                if((v * (v - 1)) == e){
                   ans++;
                }
            }
        }
        return ans;
    }
};