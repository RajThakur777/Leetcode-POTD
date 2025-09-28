// //Recursion:
// class Solution {
// public:
//     int m, n;

//     bool solve(int i, int j, string &s, string &p) {
//         if (i < 0 && j < 0) return true;
//         if (j < 0 && i >= 0) return false;
//         if (i < 0) {
//             for (int k = 0; k <= j; k++) {
//                 if (p[k] != '*') return false;
//             }
//             return true;
//         }

//         if (s[i] == p[j] || p[j] == '?') {
//             return solve(i - 1, j - 1, s, p);
//         }
//         else if (p[j] == '*') {
//             return solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
//         }
//         else {
//             return false;
//         }
//     }

//     bool isMatch(string s, string p) { 
//         m = s.size();
//         n = p.size();
//         return solve(m - 1, n - 1, s, p); 
//     }
// };





//Recursion+Memoiation:
class Solution {
public:
    int m, n;
    int dp[2001][2001];

    bool solve(int i, int j, string &s, string &p) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p);
        }
        else if (p[j] == '*') {
            return dp[i][j] = solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        }
        else {
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) { 
        m = s.size();
        n = p.size();

        memset(dp , -1 , sizeof(dp));

        return solve(m - 1, n - 1, s, p); 
    }
};
