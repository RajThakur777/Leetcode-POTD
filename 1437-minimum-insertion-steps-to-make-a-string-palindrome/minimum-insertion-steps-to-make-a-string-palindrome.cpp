// //Recursion:
// class Solution {
// public:
//     int solve(string &s , int i , int j) {
//         if(i >= j) return 0;

//         if(s[i] == s[j]) {
//             return solve(s , i+1 , j-1);
//         }
//         else {
//             return 1 + min(solve(s , i+1 , j) , solve(s , i , j-1));
//         }
//     }

//     int minInsertions(string s) {
//         int n = s.size();

//         return solve(s , 0 , n-1);
//     }
// };





//Recursion + Memoization:
class Solution {
public:
    int dp[1001][1001];
    
    int solve(string &s , int i , int j) {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = solve(s , i+1 , j-1);
        }
        else {
            return dp[i][j] = 1 + min(solve(s , i+1 , j) , solve(s , i , j-1));
        }
    }

    int minInsertions(string s) {
        int n = s.size();

        memset(dp , -1 , sizeof(dp));

        return solve(s , 0 , n-1);
    }
};