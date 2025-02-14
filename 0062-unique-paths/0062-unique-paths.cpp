// //Recursion:
// class Solution {
// public:

//     int helper(int i , int j , int m , int n){

//         if(i == m-1 && j == n-1) return 1;

//         if(i >= m || j >= n) return 0;

//         return helper(i+1 , j , m , n) + helper(i , j+1 , m , n);
//     }

//     int uniquePaths(int m, int n) {
//         int ans = helper(0 , 0 , m , n);

//         return ans;
//     }
// };




//Memoization:
//Recursion:
class Solution {
public:
    int helper(int i , int j , int m , int n , vector<vector<int>> &dp){
        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = helper(i+1 , j , m , n , dp) + helper(i , j+1 , m , n , dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
        int ans = helper(0 , 0 , m , n , dp);

        return ans;
    }
};