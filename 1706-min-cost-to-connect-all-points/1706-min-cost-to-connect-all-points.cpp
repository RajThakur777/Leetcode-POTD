//Prim's Algo - MST:
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) { 
        //build graph:
        int n = points.size();

        unordered_map<int , vector<pair<int , int>>> mpp;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x2 - x1) + abs(y2 - y1);

                mpp[i].push_back({j , d});
                mpp[j].push_back({i , d});
            }
        }
          vector<bool> inMST(n , false);

            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
            pq.push({0 , 0});

            int sum = 0;

            while(!pq.empty()) {
                auto it = pq.top();
                pq.pop();

                int node = it.second;
                int wt = it.first;

                if(inMST[node]) continue;

                inMST[node] = true;
                sum += wt;

                for(auto &v : mpp[node]) {
                    int neighbour = v.first;
                    int neighbour_wt = v.second;

                    if(inMST[neighbour] == false) {
                        pq.push({neighbour_wt , neighbour});
                    }
                }
            }
        return sum;
    }
};