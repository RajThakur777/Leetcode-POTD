//Dijktra's Algo:
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int N = edges.size();

        unordered_map<int, vector<pair<int , double>>> mpp;

        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            mpp[u].push_back({v , wt});
            mpp[v].push_back({u , wt});
        }

        vector<double> res(n , 0.0);
        res[start_node] = 1.0;

        priority_queue<pair<double , int>> pq;

        pq.push({1.0 , start_node});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            double prob = it.first;

            if(node == end_node) return prob;

            for(auto &v : mpp[node]) {
                int next_node = v.first;
                double curr = v.second;

                if((curr * prob) > res[next_node]) {
                    res[next_node] = (curr * prob);
                    pq.push({(curr * prob) , next_node});
                }
            }
        }
        if(res[end_node] == 0.0) return 0;

        return res[end_node];
    }
};