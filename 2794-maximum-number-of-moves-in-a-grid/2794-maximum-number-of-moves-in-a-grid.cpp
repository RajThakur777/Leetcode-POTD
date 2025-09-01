// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , vector<vector<int>>& grid , int prev) {
//         if(i < 0 || i >= m || j >= n) return 0;

//         if(grid[i][j] <= prev) return 0;

//         if(j == n-1) return 1;

//         int d1 = 1 + solve(i-1 , j+1 , grid , grid[i][j]);
//         int d2 = 1 + solve(i , j+1 , grid , grid[i][j]);
//         int d3 = 1 + solve(i+1 , j+1 , grid , grid[i][j]);

//         return max({d1 , d2 , d3});
//     }

//     int maxMoves(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         int ans = INT_MIN;

//         for(int row=0; row<m; row++) {
//             ans = max(ans , solve(row , 0 , grid , -1));
//         }
//         return ans-1;
//     }
// };





// //Recursion+Memoization:
// class Solution {
// public:
//     int m;
//     int n;

//     int dp[1001][1001];

//     int solve(int i , int j , vector<vector<int>>& grid , int prev) {
//         if(i < 0 || i >= m || j >= n) return 0;

//         if(grid[i][j] <= prev) return 0;

//         if(j == n-1) return 1;

//         if(dp[i][j] != -1) return dp[i][j];

//         int d1 = 1 + solve(i-1 , j+1 , grid , grid[i][j]);
//         int d2 = 1 + solve(i , j+1 , grid , grid[i][j]);
//         int d3 = 1 + solve(i+1 , j+1 , grid , grid[i][j]);

//         return dp[i][j] = max({d1 , d2 , d3});
//     }

//     int maxMoves(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         memset(dp , -1 , sizeof(dp));

//         int ans = INT_MIN;

//         for(int row=0; row<m; row++) {
//             ans = max(ans , solve(row , 0 , grid , -1));
//         }
//         return ans-1;
//     }
// };






//Tabulation:
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n));

        for(int row=0; row<m; row++) {
            dp[row][0] = 1;
        }

        int ans = 0;

        for(int j=1; j<n; j++) {
            for(int i=0; i<m; i++) {
                if((grid[i][j] > grid[i][j-1]) && dp[i][j-1] > 0) {
                    dp[i][j] = max(dp[i][j] , dp[i][j-1] + 1);         
                }

                if((i-1 >= 0 && grid[i][j] > grid[i-1][j-1]) && dp[i-1][j-1] > 0) {
                    dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1);
                }

                if((i+1 < m && grid[i][j] > grid[i+1][j-1]) && dp[i+1][j-1] > 0) {
                    dp[i][j] = max(dp[i][j] , dp[i+1][j-1] + 1);
                }
                ans = max(ans , dp[i][j] - 1);
            }
        }
        return ans;
    }
};