// //Recursion:
// class Solution {
// public:
//     int n;

//     int solve(int i , int j , vector<vector<int>>& triangle) {
//         if(i == n-1) {
//             return triangle[n-1][j];
//         }

//         if(i >= n || j >= n) return INT_MAX;

//         int down = triangle[i][j] + solve(i+1 , j , triangle);
//         int diag = triangle[i][j] + solve(i+1 , j+1 , triangle);

//         return min(down , diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) { 
//         n = triangle.size();

//         return solve(0 , 0 , triangle);  
//     }
// };




// //Recursion+Memoization:
// class Solution {
// public:
//     int n;
//     int dp[201][201];

//     int solve(int i , int j , vector<vector<int>>& triangle) {
//         if(i == n-1) {
//             return triangle[n-1][j];
//         }

//         if(dp[i][j] != -1) return dp[i][j];

//         if(i >= n || j >= n) return INT_MAX;

//         int down = triangle[i][j] + solve(i+1 , j , triangle);
//         int diag = triangle[i][j] + solve(i+1 , j+1 , triangle);

//         return dp[i][j] = min(down , diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) { 
//         n = triangle.size();

//         memset(dp , -1 , sizeof(dp));

//         return solve(0 , 0 , triangle);  
//     }
// };





//Tabulation:
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {  
        int n = triangle.size();

        vector<vector<int>> dp(n , vector<int>(n));

        for(int j=0; j<n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j] , dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};