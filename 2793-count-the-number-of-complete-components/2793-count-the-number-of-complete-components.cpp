//DFS:
class Solution {
public:

    void dfs(int &vertex , int &edges , unordered_map<int , vector<int>> &mpp , vector<bool> &visited , int node) {
        vertex++;

        visited[node] = true;

        edges += mpp[node].size();

        for(int &v : mpp[node]) {
            if(!visited[v]) {
                dfs(vertex , edges , mpp , visited , v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {  
        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        int ans = 0;

        vector<bool> visited(n , false);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int v = 0;
                int e = 0;

                dfs(v , e , mpp , visited , i);

                if((v * (v - 1)) == e) {
                    ans++;
                }
            }
        }
        return ans;
    }
};