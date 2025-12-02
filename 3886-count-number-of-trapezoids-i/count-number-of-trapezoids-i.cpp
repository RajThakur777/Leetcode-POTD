class Solution {
public:
    const int mod = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        int m = points.size();

        unordered_map<long long , long long> mpp;

        for(int i=0; i<m; i++) {
            long long x = points[i][0];
            long long y = points[i][1];

            mpp[y]++;
        }

        long long ans = 0;
        long long sum = 0;

        for(auto it : mpp) {
            long long pairs = ((it.second) * (it.second - 1)) / 2;

            ans = (ans + (pairs * sum)) % mod;

            sum += pairs;
        }
        return ans;
    }
};