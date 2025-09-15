// //Recursion:
// class Solution {
// public:

//     double solve(int i , int j , int k , int n) {
//         if(i < 0 || i >= n || j < 0 || j >= n) return 0;

//         if(k == 0) return 1;

//         double ans = 0.0;

//         ans += solve(i - 2, j + 1, k - 1 , n);
//         ans += solve(i - 2, j - 1, k - 1 , n);
//         ans += solve(i - 1, j + 2, k - 1 , n);
//         ans += solve(i - 1, j - 2, k - 1 , n);
//         ans += solve(i + 1, j + 2, k - 1 , n);
//         ans += solve(i + 1, j - 2, k - 1 , n);
//         ans += solve(i + 2, j + 1, k - 1 , n);
//         ans += solve(i + 2, j - 1, k - 1 , n);

//         return (ans) / (8.0);
//     }

//     double knightProbability(int n, int k, int row, int column) {
//         return solve(row , column , k , n);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    double dp[25][25][101];

    double solve(int i , int j , int k , int n) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (k == 0) return 1;

        if (dp[i][j][k] != -1.0) return dp[i][j][k];

        double ans = 0.0;
        ans += solve(i - 2, j + 1, k - 1 , n);
        ans += solve(i - 2, j - 1, k - 1 , n);
        ans += solve(i - 1, j + 2, k - 1 , n);
        ans += solve(i - 1, j - 2, k - 1 , n);
        ans += solve(i + 1, j + 2, k - 1 , n);
        ans += solve(i + 1, j - 2, k - 1 , n);
        ans += solve(i + 2, j + 1, k - 1 , n);
        ans += solve(i + 2, j - 1, k - 1 , n);

        return dp[i][j][k] = ans / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                for (int c = 0; c <= k; c++) {
                    dp[a][b][c] = -1.0;
                }
            }
        }
        return solve(row, column, k, n);
    }
};
