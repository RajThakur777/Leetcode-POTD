class Solution {
public:

    void dfs(int node , vector<bool> &visited , vector<int> &dist , vector<int>& edges) {
        visited[node] = true;

        int v = edges[node];

        if(v != -1 && visited[v] == false) {
            visited[v] = true;
            dist[v] = 1 + dist[node];
            dfs(v , visited , dist , edges);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n , INT_MAX);
        vector<int> dist2(n , INT_MAX);

        dist1[node1] = 0;
        dist2[node2] = 0;

        vector<bool> visited1(n , false);
        vector<bool> visited2(n , false);

        dfs(node1 , visited1 , dist1 , edges);
        dfs(node2 , visited2 , dist2 , edges);

        int res = INT_MAX;
        int t = -1;

        for(int i=0; i<n; i++) {
            if(dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int ans = max(dist1[i] , dist2[i]);

                if(ans < res) {
                    res = ans;
                    t = i;
                }
            }
        }
        return t;
    }
};