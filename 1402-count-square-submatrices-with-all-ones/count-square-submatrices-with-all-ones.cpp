// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , vector<vector<int>>& matrix) {
//         if(i >= m || j >= n || matrix[i][j] == 0) return 0;

//         int right = solve(i , j+1 , matrix);
//         int down = solve(i+1 , j , matrix);
//         int diagonal = solve(i+1 , j+1 , matrix);

//         return 1 + min({right , down , diagonal});
//     }

//     int countSquares(vector<vector<int>>& matrix) {
//         m = matrix.size();
//         n = matrix[0].size();

//         int cnt = 0;

//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(matrix[i][j] == 1) {
//                     cnt += solve(i , j , matrix);
//                 }
//             }
//         }
//         return cnt;
//     }
// };





//Memoization:
class Solution {
public:
    int m;
    int n;

    vector<vector<int>> dp;

    int solve(int i , int j , vector<vector<int>>& matrix) {
        if(i >= m || j >= n || matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i , j+1 , matrix);
        int down = solve(i+1 , j , matrix);
        int diagonal = solve(i+1 , j+1 , matrix);

        return dp[i][j] = 1 + min({right , down , diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m+1 , vector<int>(n+1 , -1)); 

        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 1) {
                    cnt += solve(i , j , matrix);
                }
            }
        }
        return cnt;
    }
};