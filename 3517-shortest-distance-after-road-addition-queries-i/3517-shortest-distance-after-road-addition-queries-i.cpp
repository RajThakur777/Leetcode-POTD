//Dijktra's Algorithm:
class Solution {
public:

    int dijktrasAlgo(unordered_map<int , vector<pair<int , int>>> &mpp , vector<int> dist , int n) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , 0});
        dist[0] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dt = pq.top().first;

            pq.pop();

            if(node == n-1) return dist[n-1];

            if(dt > dist[node]) continue;

            for(auto &v : mpp[node]) {
                int neigh = v.first;
                int d = v.second;

                if((d + dt) < dist[neigh]) {
                    dist[neigh] = d + dt;
                    pq.push({d + dt , neigh});
                }
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int N = queries.size();

        vector<int> ans;

        unordered_map<int , vector<pair<int , int>>> mpp;
        for(int i=0; i<n-1; i++) {
            mpp[i].push_back({i+1 , 1});
        }

        vector<int> dist(n , INT_MAX);

        for(int i=0; i<N; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            mpp[u].push_back({v , 1});

            int len = dijktrasAlgo(mpp , dist , n);

            ans.push_back(len);
        }
        return ans;
    }
};