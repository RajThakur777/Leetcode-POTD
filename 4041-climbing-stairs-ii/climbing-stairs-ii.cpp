class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+2);

        dp[0] = 0;

        for(int i=1; i<=n; i++) {
            long long v1 = LLONG_MAX;
            long long v2 = LLONG_MAX;
            long long v3 = LLONG_MAX;

            if((i-1) >= 0) {
                v1 = 1LL*costs[i-1] + 1LL*1 + dp[i-1];
            }

            if((i-2) >= 0) {
                v2 = 1LL*costs[i-1] + 1LL*4 + dp[i-2];
            }

            if((i-3) >= 0) {
                v3 = 1LL*costs[i-1] + 1LL*9 + dp[i-3];
            }

            dp[i] = min({v1 , v2 , v3});
        }
        return dp[n];
    }
};