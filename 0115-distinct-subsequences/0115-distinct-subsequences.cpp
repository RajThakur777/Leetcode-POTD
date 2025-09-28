// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int dp[1001][1001];

//     int solve(int i , int j , string s , string t) {
//         if(j < 0) return 1;
//         if(i < 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == t[j]) {
//             return dp[i][j] = solve(i-1 , j-1 , s , t) + solve(i-1 , j , s , t);
//         }
//         else {
//             return dp[i][j] = solve(i-1 , j , s , t);
//         }
//     }

//     int numDistinct(string s, string t) {
//         m = s.size();
//         n = t.size();

//         memset(dp , -1 , sizeof(dp));

//         return solve(m-1 , n-1 , s , t);
//     }
// };




//Tabulation:
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<double>> dp(m+1 , vector<double>(n+1));

        for(int i=0; i<=m; i++) {
            dp[i][0] = 1;
        }

        for(int j=1; j<=n; j++) {
            dp[0][j] = 0;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};