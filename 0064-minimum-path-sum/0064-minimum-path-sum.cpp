// //Recursion:
// class Solution {
// public:
//     int m, n;

//     int solve(int i, int j, vector<vector<int>>& grid) {
//         if (i >= m || j >= n) return INT_MAX;

//         if (i == m-1 && j == n-1) return grid[i][j];

//         int right = solve(i, j+1, grid);
//         int down  = solve(i+1, j, grid);

//         return grid[i][j] + min(right, down);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         return solve(0, 0, grid);
//     }
// };





// //Recursion + Memoization:
// class Solution {
// public:
//     int m, n;
//     int dp[201][201];

//     int solve(int i, int j, vector<vector<int>>& grid) {
//         if (i >= m || j >= n) return INT_MAX;

//         if (i == m-1 && j == n-1) return grid[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int right = solve(i, j+1, grid);
//         int down  = solve(i+1, j, grid);

//         return dp[i][j] = grid[i][j] + min(right, down);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         memset(dp , -1 , sizeof(dp));

//         return solve(0, 0, grid);
//     }
// };






//Tabulation:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1));

        dp[0][0] = grid[0][0];

        for(int i=1; i<m; i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int j=1; j<n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
