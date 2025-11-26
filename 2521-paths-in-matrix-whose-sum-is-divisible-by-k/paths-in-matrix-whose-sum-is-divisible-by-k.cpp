class Solution {
public:
    const int mod = 1e9 + 7;
    int m;
    int n;

    int solve(int i , int j , vector<vector<int>> &grid , int k , int sum , vector<vector<vector<int>>> &dp) {
        if(i >= m || j >= n) return 0;

        if(i == m - 1 && j == n - 1) {
            return ((sum + grid[m-1][n-1]) % k == 0) ? 1 : 0;
        }

        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        int right = solve(i , j + 1 , grid , k , (sum + grid[i][j]) % k , dp) % mod;
        int down = solve(i + 1 , j , grid , k , (sum + grid[i][j]) % k , dp) % mod;

        return dp[i][j][sum] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));

        return solve(0 , 0 , grid , k , 0 , dp);
    }
};