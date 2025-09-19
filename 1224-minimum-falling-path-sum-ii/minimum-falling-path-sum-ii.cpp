// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int i , int j , vector<vector<int>> &grid) {
//         if(i == n-1) {
//             return grid[i][j];
//         }

//         int sum = INT_MAX;

//         for(int idx=0; idx<n; idx++) {
//             if(idx != j) {
//                 sum = min(sum , solve(i+1 , idx , grid));
//             }
//         }
//         return sum + grid[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& grid) {
//         n = grid.size();

//         int ans = INT_MAX;

//         for(int i=0; i<n; i++) {
//             ans = min(ans , solve(0 , i , grid));
//         }
//         return ans;
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[201][201];

//     int solve(int i , int j , vector<vector<int>> &grid) {
//         if(i == n-1) {
//             return grid[i][j];
//         }

//         if(dp[i][j] != -1) return dp[i][j];

//         int sum = INT_MAX;

//         for(int idx=0; idx<n; idx++) {
//             if(idx != j) {
//                 sum = min(sum , solve(i+1 , idx , grid));
//             }
//         }
//         return dp[i][j] = sum + grid[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& grid) {
//         n = grid.size();

//         memset(dp , -1 , sizeof(dp));

//         int ans = INT_MAX;

//         for(int i=0; i<n; i++) {
//             ans = min(ans , solve(0 , i , grid));
//         }
//         return ans;
//     }
// };




//Tabulation:
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n , vector<int>(n));

        for(int j=0; j<n; j++) {
            dp[0][j] = grid[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = grid[i][j];

                int sum = INT_MAX;

                for(int k=0; k<n; k++) {
                    if(k != j) {
                        sum = min(sum , dp[i-1][k]);
                    }
                }

                dp[i][j] += sum;
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
            ans = min(ans , dp[n-1][j]);
        }
        return ans;
    }
};