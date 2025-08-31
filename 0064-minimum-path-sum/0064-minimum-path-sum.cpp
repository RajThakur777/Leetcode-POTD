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





//Recursion + Memoization:
class Solution {
public:
    int m, n;
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return INT_MAX;

        if (i == m-1 && j == n-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, grid);
        int down  = solve(i+1, j, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp , -1 , sizeof(dp));

        return solve(0, 0, grid);
    }
};
