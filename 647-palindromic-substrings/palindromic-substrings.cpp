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





//Recursion + Memoization:
class Solution {
public:
    int dp[1001][1001];

    bool check(string &s , int i , int j) {
        if(i > j) return true;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) {
            return check(s , i+1 , j-1);
        }
        return false;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        memset(dp , -1 , sizeof(dp));

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(check(s , i , j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};