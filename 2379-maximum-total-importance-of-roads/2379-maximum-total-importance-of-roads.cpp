class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int  N = roads.size();

        long long ans = 0;

        vector<int> count(n , 0);

        for(int i=0; i<N; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            count[u]++;
            count[v]++;
        }

        priority_queue<pair<int , int>> pq;
        for(int i=0; i<n; i++) {
            pq.push({count[i] , i});
        }

        map<int , int> mpp;
        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            mpp[node] = n;
            n--;
        }

        for(int i=0; i<N; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            ans += (mpp[u] + mpp[v]);
        }
        return ans;
    }
};