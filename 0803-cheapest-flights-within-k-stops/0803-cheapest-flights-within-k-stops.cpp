//Dijktra's Algo:
class Solution {
public:

    typedef pair<int , pair<int , int>> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int N = flights.size();

        unordered_map<int , vector<pair<int , int>>> mpp;

        for(int i=0; i<N; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            mpp[u].push_back({v , cost});
        }

        vector<vector<int>> price(n, vector<int>(k+2, INT_MAX));

        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , {src , 0}});

        price[src][0] = 0;

        while(!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int steps = pq.top().second.second;

            pq.pop();

            if (steps > k+1) continue;

            if(node == dst) return cost;

            for(auto &it : mpp[node]) {
                int neighbour = it.first;
                int c = it.second;

                if((c + cost) < price[neighbour][steps] && steps <= k) {
                    price[neighbour][steps+1] = c + cost;
                    pq.push({c + cost , {neighbour , steps + 1}});
                }
            }
        }
        return -1;
    }
};