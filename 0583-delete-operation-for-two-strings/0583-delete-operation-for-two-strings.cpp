// //Recursion:
// class Solution {
// public:
//     int m;
//     int n;

//     int solve(int i , int j , string word1 , string word2) {
//         if(i < 0 || j < 0) return 0;

//         if(word1[i] == word2[j]) {
//             return 1 + solve(i-1 , j-1 , word1 , word2);
//         }
//         else {
//             return max(solve(i-1 , j , word1 , word2) , solve(i , j-1 , word1 , word2));
//         }
//     }

//     int minDistance(string word1, string word2) {
//         m = word1.size();
//         n = word2.size();

//         int ans = solve(m-1 , n-1 , word1 , word2);

//         return (m - ans) + (n - ans);
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int m;
    int n;

    int dp[501][501];

    int solve(int i , int j , string word1 , string word2) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) {
            return dp[i][j] = 1 + solve(i-1 , j-1 , word1 , word2);
        }
        else {
            return dp[i][j] = max(solve(i-1 , j , word1 , word2) , solve(i , j-1 , word1 , word2));
        }
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(m-1 , n-1 , word1 , word2);

        return (m - ans) + (n - ans);
    }
};