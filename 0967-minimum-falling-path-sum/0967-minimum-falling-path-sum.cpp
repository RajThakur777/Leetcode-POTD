//Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , vector<vector<int>> &matrix) {
//         if(i == m-1) return matrix[i][j];

//         int mini = INT_MAX;
//         int sum = matrix[i][j];

//         if(i+1 < m) {
//             mini = min(mini , sum+solve(i+1 , j , matrix));
//         }

//         if(i+1 < m && j+1 < n) {
//             mini = min(mini , sum+solve(i+1 , j+1 , matrix));
//         }

//         if(i+1 < m && j-1 >= 0) {
//             mini = min(mini , sum+solve(i+1 , j-1 , matrix));
//         }
//         return mini;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) { 
//         m = matrix.size();
//         n = matrix[0].size();

//         int ans = INT_MAX;

//         for(int i=0; i<n; i++) {
//             ans = min(ans , solve(0 , i , matrix));
//         }
//         return ans;
//     }
// };





// //Recursion+Memoization:
// class Solution {
// public:
//     int m;
//     int n;
//     int dp[101][101];

//     int solve(int i , int j , vector<vector<int>> &matrix) {
//         if(i == m-1) return matrix[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int mini = INT_MAX;
//         int sum = matrix[i][j];

//         if(i+1 < m) {
//             mini = min(mini , sum+solve(i+1 , j , matrix));
//         }

//         if(i+1 < m && j+1 < n) {
//             mini = min(mini , sum+solve(i+1 , j+1 , matrix));
//         }

//         if(i+1 < m && j-1 >= 0) {
//             mini = min(mini , sum+solve(i+1 , j-1 , matrix));
//         }
//         return dp[i][j] = mini;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) { 
//         m = matrix.size();
//         n = matrix[0].size();

//         memset(dp , -1 , sizeof(dp));

//         int ans = INT_MAX;

//         for(int i=0; i<n; i++) {
//             ans = min(ans , solve(0 , i , matrix));
//         }
//         return ans;
//     }
// };





//Tabulation:
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) { 
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m , vector<int>(n));

        for(int col=0; col<n; col++) {
            dp[0][col] = matrix[0][col];
        }

        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                int down = dp[i-1][j];
                int left = INT_MAX;
                int right = INT_MAX;

                if(j-1 >= 0) {
                    left = dp[i-1][j-1];
                }

                if(j+1 < n) {
                    right = dp[i-1][j+1];
                }

                dp[i][j] = matrix[i][j] + min({down , left , right});
            }
        }
        return *min_element(dp[m-1].begin() , dp[m-1].end());
    }
};