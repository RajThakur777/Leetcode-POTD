class Solution {
public:

    const int mod = 1e9 + 7;

    typedef pair<long long , int> P;

    int countPaths(int n, vector<vector<int>>& roads) {
        int N = roads.size();

        unordered_map<int , vector<pair<int , int>>> mpp;

        for(int i=0; i<N; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            mpp[u].push_back({v , time});
            mpp[v].push_back({u , time});
        }

        vector<long long> dist(n , LLONG_MAX);
        vector<int> ways(n , 0);

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : mpp[node]) {
                int d = it.second;
                int neigh = it.first;

                if((d + time) < dist[neigh]) {
                    dist[neigh] = d + time;
                    pq.push({d + time , neigh});
                    ways[neigh] = ways[node];
                }
                else if((d + time == dist[neigh])) {
                    ways[neigh] = (ways[neigh] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};