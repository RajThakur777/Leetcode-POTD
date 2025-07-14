class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int N = roads.size();

        unordered_map<int , unordered_set<int>> mpp;

        for(int i=0; i<N; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            mpp[u].insert(v);
            mpp[v].insert(u);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int i_ = mpp[i].size();
                int j_ = mpp[j].size();

                int sum = i_ + j_;

                if(mpp[i].find(j) != mpp[i].end()) {
                    sum--;
                }

                ans = max(ans , sum);
            }
        }
        return ans;
    }
};