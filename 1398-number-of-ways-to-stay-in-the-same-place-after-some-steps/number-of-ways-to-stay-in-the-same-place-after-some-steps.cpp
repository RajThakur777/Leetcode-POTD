class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[501][501];

    int solve(int idx, int arrLen, int steps) {
        if (idx < 0 || idx >= arrLen) return 0;
        if (steps == 0) return idx == 0;

        if (dp[idx][steps] != -1) return dp[idx][steps];

        int op1 = solve(idx - 1, arrLen, steps - 1) % mod;
        int op2 = solve(idx, arrLen, steps - 1) % mod;
        int op3 = solve(idx + 1, arrLen, steps - 1) % mod;

        long long res = (0LL + op1 + op2 + op3) % mod;
        return dp[idx][steps] = (int)res;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        arrLen = min(arrLen, steps);
        return solve(0, arrLen, steps) % mod;
    }
};
