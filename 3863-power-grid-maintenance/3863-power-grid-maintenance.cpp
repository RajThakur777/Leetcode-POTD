class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, int id, vector<int>& nodeId, 
            unordered_map<int, set<int>>& mp, vector<bool>& visited) {
        visited[node] = true;
        mp[id].insert(node);
        nodeId[node] = id;

        for(int &ngbr : adj[node]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, id, nodeId, mp, visited);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge :  connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c+1, false);
        vector<int> nodeId(c+1);
        unordered_map<int, set<int>> mp;

        for(int node = 1; node <= c; node++) {
            if(!visited[node]) {
                int id = node;
                dfs(node, adj, id, nodeId, mp, visited);
            }
        }

        vector<int> result;
        for(auto &query : queries) {
            int type = query[0];
            int node = query[1];

            if(type == 1) {
                int id = nodeId[node];
                if(mp[id].count(node)) {
                    result.push_back(node);
                } else if(!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                int id = nodeId[node];
                mp[id].erase(node);
            }

        }
        return result;
    }
};
