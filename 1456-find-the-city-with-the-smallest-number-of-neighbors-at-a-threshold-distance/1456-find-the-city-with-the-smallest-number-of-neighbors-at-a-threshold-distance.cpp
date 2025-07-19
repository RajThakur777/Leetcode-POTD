class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int N = edges.size();

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if((dist[i][via] < INT_MAX) && (dist[via][j]) < INT_MAX)
                    dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                }
            }
        }
        vector<int> res(n);

        int city = -1;
        int reach = INT_MAX;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold && i != j) {
                    cnt++;
                }
            }
            if(cnt <= reach) {
                reach = cnt;
                city = i;
            }
        }
        return city;
    }
};