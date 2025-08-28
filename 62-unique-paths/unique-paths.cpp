// //Recursion:
// class Solution {
// public:
   
//     int solve(int i , int j , int m , int n) {
//         if(i == m-1 && j == n-1) return 1;

//         if(i < 0 || i >= m || j < 0 || j >= n) return 0;

//         int right = solve(i , j+1 , m , n);
//         int down = solve(i+1 , j , m , n);

//         return right + down;
//     }

//     int uniquePaths(int m, int n) {
//         return solve(0 , 0 , m , n);
//     }
// };





// //Recursion + Memoization:
// class Solution {
// public:
//     int dp[101][101];

//     int solve(int i , int j , int m , int n) {
//         if(i == m-1 && j == n-1) return 1;

//         if(i < 0 || i >= m || j < 0 || j >= n) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int right = solve(i , j+1 , m , n);
//         int down = solve(i+1 , j , m , n);

//         return dp[i][j] = right + down;
//     }

//     int uniquePaths(int m, int n) {
//         memset(dp , -1 , sizeof(dp));

//         return solve(0 , 0 , m , n);
//     }
// };







//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n));

        dp[0][0] = 1;
        for(int col=1; col<n; col++) {
            dp[0][col] = 1;
        }

        for(int row=1; row<m; row++) {
            dp[row][0] = 1;
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};