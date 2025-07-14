//Binary Search + DFS:
class Solution {
public:

    void dfs(vector<vector<pair<int , int>>> &adj , int node , vector<bool> &visited , int mid) {
        visited[node] = true;

        for(auto &it : adj[node]) {
            int v = it.first;
            int t = it.second;
            if(!visited[v] && (t > mid)) {
                dfs(adj , v , visited , mid);
            }
        }
    }

    bool check(int mid , vector<vector<pair<int , int>>> &adj , int n , int k) {
        vector<bool> visited(n , false);

        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj , i , visited , mid);
                cnt++;
            }
        }
        return cnt >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int N = edges.size();

        int l = 0;
        int r = 0;

        vector<vector<pair<int , int>>> adj(n);
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];

            adj[u].push_back({v , t});
            adj[v].push_back({u , t});
            r = max(r , t);
        }

        int ans = 0;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(check(mid , adj , n , k)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};