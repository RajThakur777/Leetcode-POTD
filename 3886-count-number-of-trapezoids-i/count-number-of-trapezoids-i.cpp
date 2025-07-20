class Solution {
public:
    const int mod = 1e9 + 7;
    
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<long long , long long> mpp_y;
        for(int i=0; i<n; i++) {
            mpp_y[points[i][1]]++;
        }

        long long ans = 0;
        long long total = 0;
        
        for(auto &it : mpp_y) {
            long long lines = (((it.second) * (it.second - 1)) / 2);
            ans = (ans + total * lines) % mod;
            total = (total + lines) % mod;
        }
        return (int) ans;
    }
};