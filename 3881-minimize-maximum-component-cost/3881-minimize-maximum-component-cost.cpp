class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int limit) {
        visited[node] = true;
        for (auto [nei, w] : adj[node]) {
            if (!visited[nei] && w <= limit) {
                dfs(nei, adj, visited, limit);
            }
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
      vector<vector<pair<int, int>>> adj(n);
        int maxEdge = 0;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
            maxEdge = max(maxEdge, e[2]);
        }

        int left = 0, right = maxEdge;
        int result = maxEdge;

        while (left <= right) {
            int mid = (left + right) / 2;
            vector<bool> visited(n, false);
            int components = 0;

            // Count components using DFS
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    components++;
                    dfs(i, adj, visited, mid);
                }
            }

            if (components <= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
        
        
    }
};