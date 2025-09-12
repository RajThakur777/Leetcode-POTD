class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);

        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            int I2 = dp[i2] * 2;
            int I3 = dp[i3] * 3;
            int I5 = dp[i5] * 5;

            int mini = min({I2 , I3 , I5});

            dp[i] = mini;

            if(I2 == mini) {
                i2++;
            }

            if(I3 == mini) {
                i3++;
            }

            if(I5 == mini) {
                i5++;
            }
        }
        return dp[n];
    }
};