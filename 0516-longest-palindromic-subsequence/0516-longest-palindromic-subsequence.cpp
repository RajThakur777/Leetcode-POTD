// //Recursion:
// class Solution {
// public:
//     int solve(string &s , int i , int j) {
//         if(i > j) return 0;

//         if(i == j) return 1;

//         if(s[i] == s[j]) {
//             return 2 + solve(s , i+1 , j-1);
//         }
//         else {
//             return max(solve(s , i , j-1) , solve(s , i+1 , j));
//         }
//     }

//     int longestPalindromeSubseq(string s) {
//         int n = s.size();

//         return solve(s , 0 , n-1);
//     }
// };





// //Recursion + Memoization:
// class Solution {
// public:
//     int dp[1001][1001];

//     int solve(string &s , int i , int j) {
//         if(i > j) return 0;

//         if(i == j) return 1;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == s[j]) {
//             return dp[i][j] = 2 + solve(s , i+1 , j-1);
//         }
//         else {
//             return dp[i][j] = max(solve(s , i , j-1) , solve(s , i+1 , j));
//         }
//     }

//     int longestPalindromeSubseq(string s) {
//         int n = s.size();

//         memset(dp , -1 , sizeof(dp));

//         return solve(s , 0 , n-1);
//     }
// };




//Tabulation:
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n , vector<int>(n));

        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
        }

        for(int L=2; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i][j-1] , dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};