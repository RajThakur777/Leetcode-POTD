class Graph {
public:
    typedef pair<int , int> P;
    int V;

    int dijktra(int src , int dest , unordered_map<int , vector<pair<int , int>>> &mpp) {
        priority_queue<P , vector<P> , greater<P>> pq;
        pq.push({0 , src});

        vector<int> dist(V , INT_MAX);

        while(!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;

            pq.pop();

            if(node == dest) return dist[dest] == INT_MAX ? 0 : dist[dest];

            for(auto &it : mpp[node]) {
                int neigh = it.first;
                int wt = it.second;

                if(cost + wt < dist[neigh]) {
                    dist[neigh] = cost + wt;
                    pq.push({cost + wt , neigh});
                }
            }
        }
        return -1;
    }

    unordered_map<int , vector<pair<int , int>>> mpp;
    Graph(int n, vector<vector<int>>& edges) {
        V = n;
        int N = edges.size();

        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];

            mpp[u].push_back({v , cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        mpp[u].push_back({v , cost});
    }
    
    int shortestPath(int node1, int node2) {
        return dijktra(node1 , node2 , mpp);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */