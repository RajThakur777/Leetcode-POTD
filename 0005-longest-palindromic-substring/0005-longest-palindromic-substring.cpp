// //Recursion:
// class Solution {
// public:

//     bool check(string &s , int i , int j) {
//         if(i > j) return true;

//         if(s[i] == s[j]) {
//             return check(s , i+1 , j-1);
//         }
//         return false;
//     }

//     string longestPalindrome(string s) {
//         int n = s.size();

//         string ans;

//         for(int i=0; i<n; i++) {
//             for(int j=i; j<n; j++) {
//                 if(check(s , i , j)){
//                     if((j-i+1) > ans.size()) {
//                         ans = s.substr(i , j-i+1);
//                     }
//                 }
//             }
//         }
//         return ans;
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

//     string longestPalindrome(string s) {
//         int n = s.size();

//         string ans;

//         memset(dp , -1 , sizeof(dp));

//         for(int i=0; i<n; i++) {
//             for(int j=i; j<n; j++) {
//                 if(check(s , i , j)){
//                     if((j-i+1) > ans.size()) {
//                         ans = s.substr(i , j-i+1);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };






//Tabulation:
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string ans;

        vector<vector<bool>> dp(n , vector<bool>(n , false));

        int maxiLength = 0;
        int idx = 0;

        for(int i=0; i<n; i++) {
            dp[i][i] = true;
            maxiLength = 1;
            idx = 0;
        }

        for(int L=2; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;

                if(s[i] == s[j] && L == 2) {
                    dp[i][j] = true;
                    idx = i;
                    maxiLength = 2;
                }
                else if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if((j-i+1) > maxiLength) {
                        maxiLength = j-i+1;
                        idx = i;
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(idx , maxiLength);
    }
};