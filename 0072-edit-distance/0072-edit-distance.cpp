// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(string &word1 , string &word2 , int i , int j) {
//         if(i == m) {
//             return (n - j);
//         }
//         else if(j == n) {
//             return (m - i);
//         }

//         if(word1[i] == word2[j]) {
//             return solve(word1 , word2 , i+1 , j+1);
//         }
//         int op1 = 1 + solve(word1 , word2 , i+1 , j);
//         int op2 = 1 + solve(word1 , word2 , i , j+1);
//         int op3 = 1 + solve(word1 , word2 , i+1 , j+1);

//         return min({op1 , op2 , op3});
//     }

//     int minDistance(string word1, string word2) { 
//         m = word1.size();
//         n = word2.size();

//         return solve(word1 , word2 , 0 , 0);
//     }
// };






// //Recursion + Memoization:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(string &word1 , string &word2 , int i , int j , vector<vector<int>> &dp) {
//         if(i == m) {
//             return (n - j);
//         }
//         else if(j == n) {
//             return (m - i);
//         }

//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i] == word2[j]) {
//             return dp[i][j] = solve(word1 , word2 , i+1 , j+1 , dp);
//         }
//         int op1 = 1 + solve(word1 , word2 , i+1 , j , dp);
//         int op2 = 1 + solve(word1 , word2 , i , j+1 , dp);
//         int op3 = 1 + solve(word1 , word2 , i+1 , j+1 , dp);

//         return dp[i][j] = min({op1 , op2 , op3});
//     }

//     int minDistance(string word1, string word2) { 
//         m = word1.size();
//         n = word2.size();

//         vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

//         return solve(word1 , word2 , 0 , 0 , dp);
//     }
// };







// //Recursion + Memoization:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(string &word1 , string &word2 , int m , int n , vector<vector<int>> &dp) {
//         if(m == 0 || n == 0) {
//             return (m + n);
//         }

//         if(dp[m][n] != -1) return dp[m][n];

//         if(word1[m-1] == word2[n-1]) {
//             return dp[m][n] = solve(word1 , word2 , m-1 , n-1 , dp);
//         }
//         int op1 = 1 + solve(word1 , word2 , m , n-1 , dp);
//         int op2 = 1 + solve(word1 , word2 , m-1 , n , dp);
//         int op3 = 1 + solve(word1 , word2 , m-1 , n-1 , dp);

//         return dp[m][n] = min({op1 , op2 , op3});
//     }

//     int minDistance(string word1, string word2) { 
//         m = word1.size();
//         n = word2.size();

//         vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

//         return solve(word1 , word2 , m , n , dp);
//     }
// };








//Tabulation:
class Solution {
public:
    int minDistance(string word1, string word2) { 
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1 , vector<int>(n+1));

        for(int i=0; i<m+1; i++) {
            for(int j=0; j<n+1; j++) {
                if((i == 0 || j == 0)) {
                    dp[i][j] = (i+j);
                }
                else if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i][j-1] , dp[i-1][j] , dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};