//DFS:
class Solution {
public:
    int mini = INT_MAX;

    void dfs(unordered_map<int , vector<pair<int , int>>> &mpp , int node , vector<bool> &visited) {
        visited[node] = true;

        for(auto &v : mpp[node]) {
            int t = v.first;
            int wt = v.second;

            mini = min(mini , wt);

            if(!visited[t]) {
                dfs(mpp , t , visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> visited(n + 1, false);

        unordered_map<int, vector<pair<int, int>>> mpp;

        for (auto &road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            mpp[u].push_back({v, wt});
            mpp[v].push_back({u, wt});
        }

        dfs(mpp, 1, visited);
        return mini;
    }
};
