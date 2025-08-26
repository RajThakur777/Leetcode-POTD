// //Recursion-> brute force:
// class Solution {
// public:
//     bool check(string &s , int i , int j) {
//         if(i > j) return true;

//         if(s[i] == s[j]) {
//             return check(s , i+1 , j-1);
//         }
//         return false;
//     }

//     int countSubstrings(string s) {
//         int cnt = 0;
//         int n = s.size();

//         for(int i=0; i<n; i++) {
//             for(int j=i; j<n; j++) {
//                 if(check(s , i , j)) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };





// //Recursion + Memoization:
// class Solution {
// public:
//     int dp[1001][1001];

//     bool check(string &s , int i , int j) {
//         if(i > j) return true;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == s[j]) {
//             return dp[i][j] = check(s , i+1 , j-1);
//         }
//         return dp[i][j] = false;
//     }

//     int countSubstrings(string s) {
//         int cnt = 0;
//         int n = s.size();

//         memset(dp , -1 , sizeof(dp));

//         for(int i=0; i<n; i++) {
//             for(int j=i; j<n; j++) {
//                 if(check(s , i , j)) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };





//Tabulation-> Blueprint for Palindromic DP Problems:
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int cnt = 0;

        vector<vector<bool>> dp(n+1 , vector<bool>(n+1 , false));

        for(int L=1; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;

                if(i == j) {
                    dp[i][j] = true;
                }
                else if(i+1 == j) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};