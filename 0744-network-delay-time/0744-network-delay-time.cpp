class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int N = times.size();

        unordered_map<int , vector<pair<int , int>>> mpp;
        for(int i=0; i<N; i++) {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];

            mpp[u].push_back({v , t});
        } 

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        vector<int> dist(n+1 , 1e9);
        dist[k] = 0;
        pq.push({0 , k});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto &it: mpp[u]) {
                int node = it.first;
                int wt = it.second;

                if((d + wt) < dist[node]) {
                    dist[node] = d + wt;
                    pq.push({d + wt , node});
                }
            }
        }

        int ans = 0;

        for(int i=1; i<=n; i++) {
            if(dist[i] == 1e9) return -1;

            ans = max(ans , dist[i]);
        }
        return ans;
    }
};